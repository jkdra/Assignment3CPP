//
// Created by Jawad Khadra on 10/26/24.
//

#include "header.h"

using namespace std;

/*
 * printHeadingConsole - Print the heading of the lab to the console
 * @return void
 */
void printHeadingConsole() {
    cout
    << " * AUTHOR : Jawad Khadra\n"
    << " * STUDENT ID : 1312092 (IVC)\n"
    << " * Assignment #3 - DVD\n"
    << " * CLASS : CS1B\n"
    << " * SECTION : MW: 7:30p - 9:50p\n"
    << " * DUE DATE : Oct. 28, 2024\n\n"
    << endl;
}

/*
 * printHeadingFile - Print the heading of the lab to the file
 * @param outFile - Output file stream
 * @return void
 */
void printHeadingFile(ofstream &outFile) {
    outFile
    << " * AUTHOR : Jawad Khadra\n"
    << " * STUDENT ID : 1312092 (IVC)\n"
    << " * Assignment #3 - DVD\n"
    << " * CLASS : CS1B\n"
    << " * SECTION : MW: 7:30p - 9:50p\n"
    << " * DUE DATE : Oct. 28, 2024\n\n"
    << endl;
}

/*
 * showDVDMenu - Show the menu for the assignment
 * @return void
 */
void showDVDMenu() {
    cout
    << "\n\nDVD MENU:\n"
    << "1 – Output Entire List\n"
    << "2 - Title Search\n"
    << "3 - Genre Search\n"
    << "4 - Actor Search\n"
    << "5 - Year Search\n"
    << "6 - Rating Search\n"
    << "0 – EXIT\n"
    << "Enter an option (0 to exit): ";
}

/*
 * fileSetup - Allow the user to specify an input and output files. Allow the user the option to use a default file.
 * @param inFile - Input file stream
 * @param outFile - Output file stream
 * @param movieList - Movie list
 * @return void
 */
void fileSetup(ofstream &outFile, Movie *&movieList) {

    ifstream inFile;     // INPUT - Input file stream. This is declared here since it will only be used once.
    string inFileName;   // INPUT - Name of the input file
    string outFileName;  // INPUT - Name of the output file

    cout << "\nWhich input file would you like to use? (type d for default)\n";
    getline(cin, inFileName);


    inFile.open(inFileName == "d" ? "InFile.txt" : inFileName, ios::in);

    if (inFile.fail()) {
        cerr << "\nCould not open the input file\n";
        exit(EXIT_FAILURE);
    }

    cout << "\nWhich output file would you like to use? (type d for default)\n";
    getline(cin, outFileName);

    outFile.open(outFileName == "d" ? "OFile.txt" : outFileName, ios::out);  // Open the output file

    if (outFile.fail()) {
        cerr << "\nCould not open the output file\n";
        exit(EXIT_FAILURE);
    }

    // Assuming the output would work at this point, we can print the heading of the lab here
    printHeadingFile(outFile);

    // Take the movies from the input file and put them into a linked list
    while (true) {
        Movie* newMovie = new Movie;

        // INPUT - Read movie details from file and check for input failure
        if (!getline(inFile, newMovie -> title) ||
            !getline(inFile, newMovie -> lead) ||
            !getline(inFile, newMovie -> supporting) ||
            !getline(inFile, newMovie -> genre) ||
            !getline(inFile, newMovie -> altGenre) ||
            !(inFile >> newMovie -> year) ||
            !(inFile >> newMovie -> rating)) {
            delete newMovie;  // Free memory if read fails at any point
            break;            // Exit loop on read failure or end of data
        }

        inFile.ignore();  // Ignore the newline character after rating
        getline(inFile, newMovie->plot);  // Read the plot description

        // LINKING - Insert new movie at the beginning of the list
        newMovie -> next = movieList;
        movieList = newMovie;
    }

    // Close the input file
    inFile.close();
}

/*
 * formatPlot
 *
 * format the plot of the movie to fit in a 75 character line
 *
 * @param plot - Plot of the movie
 * @return string - Formatted plot
 */
string formatPlot(const string &plot) {
    stringstream formattedPlot;   // OUTPUT - Formatted plot
    string word;                  // INPUT - Current word
    int lineLength = 0;           // CALC - Length of the current line

    for (size_t i = 0; i < plot.length(); ++i) {
        char ch = plot[i];

        // If we encounter a space or the end of the string, we have a full word
        if (isspace(ch) || i == plot.length() - 1) {
            if (i == plot.length() - 1 && !isspace(ch)) word += ch;  // Include the last character if it's not a space

            // Check if adding this word would exceed the max line length of 75
            if (lineLength + word.length() > 75) {
                formattedPlot << "\n";  // New line if we exceed the limit
                lineLength = 0;
            }

            formattedPlot << word << " ";
            lineLength += word.length() + 1;  // Update line length
            word.clear();  // Reset the word for the next one
        } else word += ch;  // Keep building the current word
    }

    return formattedPlot.str();
}

/*
 * printShortMovieListing
 *
 * print the movie listings to the output file
 *
 * @param movieList
 * @param outFile
 */
void printShortMovieListing(Movie* movieList, fstream &outFile, const int numMovies) {
    outFile
    << "MOVIE #  TITLE                                           YEAR RATING  GENRE             ALT GENRE         LEAD ACTOR          SUPPORTING ACTOR\n"
    << "------- ------------------------------------------------ ---- ------ ----------------- ----------------- ------------------- -------------------\n";
    for (int i = 0; i < numMovies; ++i) {
        outFile
        << internal << setw(4) << i + 1 << "  "
        << left << setw(40) << movieList -> title << "  "
        << setw(4) << movieList -> year << "  " << internal << setw(5) << movieList -> rating << "  "
        << left << setw(20) << movieList -> genre << "  " << setw(20) << movieList -> altGenre << "  " << setw(36) << movieList -> lead << "  " << setw(36) << movieList -> supporting << "\n";
        movieList = movieList -> next;
    }
}

/*
 * printLongMovieListing
 *
 * print the movie listings to the output file
 *
 * @param movieList
 * @param outFile
 */
void printLongMovieListing(Movie* movieList, fstream &outFile) {
    outFile
    << "\n\n***************************************************************************\n"
    << "Title:  " << movieList -> title << "\n"
    << "---------------------------------------------------------------------------\n"
    << "Year:   " << movieList -> year << "\t" << "Rating: " << movieList -> rating << "\n"
    << "---------------------------------------------------------------------------\n"
    << "Leading Actor:  " << left << setw(36) << movieList -> lead << "Genre 1:  " << movieList -> genre << "\n"
    << "Supporting Actor: " << movieList -> supporting << " Genre 2: " << movieList -> altGenre << "\n"
    << "---------------------------------------------------------------------------\n"
    << "PLOT:\n" << formatPlot(movieList -> plot) << "\n"
    << "***************************************************************************\n"
    ;
}

/*
 * titleSearch
 *
 * search the linked list for a movie with the given title
 *
 * @param movieList
 * @param title
 * @return
 */
void titleSearch(Movie* head, const string& title, fstream &outFile) {
    Movie* current = head;
    bool found = false;     // FLAG - Tracks if the movie is found

    while (current != nullptr) {
        if (current->title == title) {
            // OUTPUT - Call user's function to output full movie details
            printLongMovieListing(current, outFile);
            found = true;
            break;
        }
        current = current->next;
    }

    if (!found) cout << "Movie titled '" << title << "' not found.\n";
}
