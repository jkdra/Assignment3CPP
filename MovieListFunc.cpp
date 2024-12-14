//
// Created by Jawad Khadra on 12/12/24.
//

#include "MovieListHeader.h"

using namespace std;

/*
 * MovieList
 *
 * Constructor & Destructor
 */
MovieList::MovieList() {
    head = nullptr;
    stackCount = 0;
}

MovieList::~MovieList() {
    DVDNode* current = head;
    DVDNode* next;

    while (current != nullptr) {
        next = current -> next;
        delete current;
        current = next;
    }
}

/*
 * CreateList
 *
 * This method is used to create a linked list of DVD nodes
 */
void MovieList::CreateList(string inputFileName) {
    ifstream inFile(inputFileName, ios::in);  // Open the input file

    if (inFile.fail()) {
        cerr << "\nCould not open the input file\n";
        exit(EXIT_FAILURE);
    }

    // Read the input file and create a linked list of DVD nodes
    while (!inFile.eof()) {
        auto* newMovie = new DVDNode;  // Allocate new memory for each movie node

        // INPUT - Read movie details from file and check for input failure
        getline(inFile, newMovie->title);
        getline(inFile, newMovie->leadingActor);
        getline(inFile, newMovie->supportingActor);
        getline(inFile, newMovie->genre);
        getline(inFile, newMovie->alternateGenre);
        inFile >> newMovie->year;
        inFile.ignore();  // Ignore the newline character after year
        inFile >> newMovie->rating;
        inFile.ignore();  // Ignore the newline character after rating
        getline(inFile, newMovie->synopsis);  // Read the plot description

        // Skip the blank line separating movies, if present
        inFile.ignore();

        // LINKING - Insert new movie at the beginning of the list
        newMovie->next = head;
        head = newMovie;
    }

    // Close the input file
    inFile.close();
}

/*
 * OutputList
 *
 * This method is used to output the linked list of DVD nodes to a file
 */
void MovieList::OutputList(string outputFileName) {
    ofstream outFile;  // OUTPUT - The output file stream

    // Open the output file
    outFile.open(outputFileName, ios::out || ios::app);

    if (outFile.fail()) {
        cerr << "\nCould not open the output file\n";
        exit(EXIT_FAILURE);
    }

    printClassHeader(outputFileName);

    // Traverse and output each movie in the list
    DVDNode* current = head;
    int count = 1;
    while (current != nullptr) {
        outFile
        << "\n***************************************************************************\n"
        << "MOVIE #" << count << "\t\t" << "TITLE: " << TitleShortener(current -> title) << "\n"
        << "---------------------------------------------------------------------------\n"
        << "Year: " << current -> year << "\t\t  " << "Rating: " << current -> rating << "\n"
        << "---------------------------------------------------------------------------\n"
        << left << setw(18) << "Leading Actor:" << setw(32) << current -> leadingActor << "Genre 1: " << current -> genre << "\n"
        << left << setw(18) << "Supporting Actor:" << setw(32) << current -> supportingActor << "Genre 2: " << current -> alternateGenre << "\n"
        << "---------------------------------------------------------------------------\n"
        << "PLOT:\n" << WordWrap(current -> synopsis) << "\n"
        << "***************************************************************************\n";
        current = current->next;  // Move to the next movie
        count++;
    }

    // Close the output file
    outFile.close();
}

/*
 * WordWrap
 *
 * Wraps the plot of the movie to fit in a 75 character line
 *
 * @param plot - Plot of the movie
 * @return string - Formatted plot
 */
string MovieList::WordWrap(string plot) {
    ostringstream wordWarp;   // OUTPUT - Formatted plot
    string word;                  // INPUT - Current word
    int lineLength = 0;           // CALC - Length of the current line

    for (size_t i = 0; i < plot.length(); ++i) {
        char ch = plot[i];

        // If we encounter a space or the end of the string, we have a full word
        if (isspace(ch) || i == plot.length() - 1) {
            if (i == plot.length() - 1 && !isspace(ch)) word += ch;  // Include the last character if it's not a space

            // Check if adding this word would exceed the max line length of 75
            if (lineLength + word.length() > 75) {
                wordWarp << "\n";  // New line if we exceed the limit
                lineLength = 0;
            }

            wordWarp << word << " ";
            lineLength += word.length() + 1;  // Update line length
            word.clear();  // Reset the word for the next one
        } else word += ch;  // Keep building the current word
    }

    return wordWarp.str();
}

/*
 * TitleShortener
 *
 * Concatenates the title of the movie using ... (ellipsis)
 *
 * @param title - Title of the movie
 * @return string - Concatenated title and year
 */
string MovieList::TitleShortener(string title) {
    const size_t maxLength = 50;  // Maximum allowed length for the title

    // If title length exceeds maxLength, truncate and append "..."
    if (title.length() > maxLength) return title.substr(0, maxLength - 3) + "...";

    // If it's already within the limit, return the original title
    return title;
}

/*
 * printClassHeader
 *
 * Prints the class header to the output file
 *
 * @param outputFileName - Name of the output file
 */
void MovieList::printClassHeader(string outputFileName) {
    ofstream outFile;  // OUTPUT - The output file stream

    // Open the output file
    outFile.open(outputFileName, ios::out);

    outFile
    << " * AUTHOR : Jawad Khadra\n"
    << " * STUDENT ID : 1312092 (IVC)\n"
    << " * Assignment #5 - DVD Movie List\n"
    << " * CLASS : CS1B\n"
    << " * SECTION : MW: 7:30p - 9:50p\n"
    << " * DUE DATE : Dec. 13, 2024\n\n"
    << endl;

    outFile.close();
}