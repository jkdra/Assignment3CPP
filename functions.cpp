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
    << " * DUE DATE : Oct. 28, 2024\n"
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
    << " * DUE DATE : Oct. 28, 2024\n"
    << endl;
}

/*
 * showDVDMenu - Show the menu for the assignment
 * @return void
 */
void showDVDMenu() {
    cout
    << "\nDVD MENU:\n"
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
 * handleMenuSelection
 *
 * Handles the user's menu selection and calls the appropriate search function.
 *
 * @param option - Menu selection
 * @param movieList - Pointer to the head of the movie list
 * @param outFile - File stream for outputting results
 */
void handleMenuSelection(MENU_OPTIONS option, Movie*& movieList, ofstream &outFile) {

    string searchTerm;    // INPUT - Stores the search term for various options
    int numericSearch;    // INPUT - Stores numeric search terms for year and rating

    switch (option) {
        case OUTPUT_LIST:  // Output Entire List
            cout << "\nListing all movies!" << endl;
            outputEntireList(movieList, outFile);
            break;
        case TITLE_SEARCH:  // Title Search
            cout << "\nWhich title are you looking for? ";
            getline(cin, searchTerm);
            titleSearch(movieList, searchTerm, outFile);
            break;
        case GENRE_SEARCH:  // Genre Search
            cout << "\nWhich genre are you looking for? ";
            getline(cin, searchTerm);
            genreSearch(movieList, searchTerm, outFile);
            break;
        case ACTOR_SEARCH:  // Actor Search
            cout << "\nWhich actor are you looking for? ";
            getline(cin, searchTerm);
            actorSearch(movieList, searchTerm, outFile);
            break;

        case YEAR_SEARCH:  // Year Search
            cout << "\nWhich year are you looking for? ";
            cin >> numericSearch;
            cin.ignore();
            if (cin.fail()) {
                cout << "\n**** Please input a NUMBER between 1878 and 3000 ****\n";
                cin.clear();
                cin.ignore();
            }
            else if (numericSearch < 1878 || numericSearch > 3000) {
                cout << "\n**** The number " << numericSearch <<" is an invalid entry.            ****\n";
                cout << "**** Please input a valid year between 1878 and 3000 ****" << endl;
            }
            else yearSearch(movieList, numericSearch, outFile);
            break;

        case RATING_SEARCH:  // Rating Search
            cout << "\nWhich rating are you looking for? ";
            cin >> numericSearch;
            cin.ignore();
            if (cin.fail()) {
                cout << "\n**** Please input a NUMBER between 0 and 9 ****\n";
                cin.clear();
                cin.ignore();
            }
            else if (numericSearch < 0 || numericSearch > 9) {
                cout
                << "\n**** The number " << numericSearch << " is an invalid entry.            ****\n"
                << "**** Please input a valid rating between 0 and 9 ****" << endl;
            }
            else ratingSearch(movieList, numericSearch, outFile);
            break;
        case EXIT:  // Exit
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "**** Invalid option, please try again ****" << endl;
            break;
    }
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
    while (!inFile.eof()) {
        auto* newMovie = new Movie;  // Allocate new memory for each movie node

        // INPUT - Read movie details from file and check for input failure
        getline(inFile, newMovie->title);
        getline(inFile, newMovie->lead);
        getline(inFile, newMovie->supporting);
        getline(inFile, newMovie->genre);
        getline(inFile, newMovie->altGenre);
        inFile >> newMovie->year;
        inFile >> newMovie->rating;

        inFile.ignore();  // Ignore the newline character after rating
        getline(inFile, newMovie->plot);  // Read the plot description

        // Skip the blank line separating movies, if present
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');

        // LINKING - Insert new movie at the beginning of the list
        newMovie->next = movieList;
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
string formatPlot(string &plot) {
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
 * Prints the movies in a listed format to the output file.
 *
 * @param movieList - Pointer to the head of the linked list of movies
 * @param outFile - File stream for outputting results
 */
void printShortMovieListing(const Movie* movieList, ofstream &outFile, int movieCount) {
    outFile
    << right << setw(5) << movieCount << "   "
    << left << setw(46) << movieList -> title << " "
    << setw(4) << movieList -> year << " "
    << right << setw(4) << movieList -> rating << "   "
    << left << setw(17) << movieList -> genre << " "
    << setw(17) << movieList -> altGenre << " "
    << setw(19) << movieList -> lead << " "
    << setw(19) << movieList -> supporting << "\n";

    movieList = movieList -> next; // Move to the next node
}

/*
 * printLongMovieListing
 *
 * print a detailed version of the movie listing to the output file
 *
 * @param movieList
 * @param outFile
 */
void printLongMovieListing(Movie* movieList, ofstream &outFile) {

    outFile
    << "\n***************************************************************************\n"
    << "Title: " << movieList -> title << "\n"
    << "---------------------------------------------------------------------------\n"
    << "Year: " << movieList -> year << "\t\t  " << "Rating: " << movieList -> rating << "\n"
    << "---------------------------------------------------------------------------\n"
    << left << setw(18) << "Leading Actor:" << setw(32) << movieList -> lead << "Genre 1: " << movieList -> genre << "\n"
    << left << setw(18) << "Supporting Actor:" << setw(32) << movieList -> supporting << "Genre 2: " << movieList -> altGenre << "\n"
    << "---------------------------------------------------------------------------\n"
    << "PLOT:\n" << formatPlot(movieList -> plot) << "\n"
    << "***************************************************************************\n\n\n"
    ;
}

/*
 * outputEntireList
 *
 * Traverses and outputs all movies in the list using the short listing format.
 *
 * @param head - Pointer to the head of the movie list (will not be modified)
 * @param outFile - File stream for outputting results
 */
void outputEntireList(Movie* head, ofstream &outFile) {
    Movie* current = head;  // POINTER - Start from the head but do not alter it
    int count = 1;          // COUNTER - Tracks the movie number in the list

    // Output header for the full list
    outFile << "COMPLETE MOVIE LISTING:\n";
    outFile << "MOVIE #  TITLE                                           YEAR RATING  GENRE             ALT GENRE         LEAD ACTOR          SUPPORTING ACTOR\n";
    outFile << "------- ------------------------------------------------ ---- ------ ----------------- ----------------- ------------------- -------------------\n";

    // Traverse and output each movie in the list
    while (current != nullptr) {
        // OUTPUT - Call the short listing function for each movie
        printShortMovieListing(current, outFile, count);
        current = current->next;  // Move to the next movie
        count++;
    }
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
void titleSearch(Movie* head, const string& title, ofstream &outFile) {
    Movie* current = head;  // INPUT - The current movie node being processed
    bool found = false;     // FLAG - Tracks if the movie with the title is found

    cout << "\nSearching for the title " << title << endl;

    // Traverse the linked list to find the first matching title
    while (current != nullptr) {
        if (current -> title == title) {
            // Output header and call printLongMovieListing for the full movie details
            printLongMovieListing(current, outFile);
            found = true;
            break;  // Exit the loop once the movie is found
        }
        current = current->next;
    }

    // Provide feedback on search results
    if (!found) cout << "Sorry, the movie \"" << title << "\" was not found.\n";
    else cout << "Found the movie " << title << "!\n";
}

/*
 * genreSearch
 *
 * Searches the linked list for movies with the specified genre and outputs each matching movie.
 *
 * @param head - Pointer to the head of the movie list
 * @param genre - Genre to search for
 * @param outFile - File stream for outputting results
 */
void genreSearch(Movie* head, const string& genre, ofstream &outFile) {
    Movie* current = head;  // INPUT - The current movie node being processed
    int count = 0;          // COUNTER - Tracks the number of movies found

    // Traverse the entire linked list to find all matches
    while (current != nullptr) {
        // Check if the current movie matches the specified genre or alt genre
        if (current -> genre == genre || current -> altGenre == genre) {
            // Output header only once, when the first match is found
            if (count == 0) {
                outFile << "\nSearch by genre for '" << genre << "' found:\n";
                outFile
                << "MOVIE # TITLE                                          YEAR RATING GENRE             ALT GENRE         LEAD ACTOR          SUPPORTING ACTOR\n"
                << "------- ---------------------------------------------- ---- ------ ----------------- ----------------- ------------------- -------------------\n";
            }

            // Output the movie's details using the short listing function
            printShortMovieListing(current, outFile, count + 1);
            count++;
        }
        current = current->next;
    }
    // Add Spacing after the search results
    outFile << "\n";

    // Provide feedback on search results
    if (count == 0) cout << "Sorry, no movies for the genre " << genre << " were found.\n";
    else cout << "Found " << count << " movie(s) for the genre " << genre << "!\n";
}

/*
 * actorSearch
 *
 * Searches the linked list for movies with the specified actor and outputs each matching movie.
 *
 * @param head - Pointer to the head of the movie list
 * @param actor - Actor to search for
 * @param outFile - File stream for outputting results
 */
void actorSearch(Movie* head, const string& actor, ofstream &outFile) {
    Movie* current = head;  // INPUT - The current movie node being processed
    int count = 0;          // COUNTER & FLAG - Keeps track of the number of movies found

    while (current != nullptr) {
        if (current -> lead == actor || current -> supporting == actor) {
           // Output header only once, when the first match is found
            if (count == 0) {
                outFile << "\nSearch by actor for " << actor << " found:\n";
                outFile
                << "MOVIE # TITLE                                          YEAR RATING GENRE             ALT GENRE         LEAD ACTOR          SUPPORTING ACTOR\n"
                << "------- ---------------------------------------------- ---- ------ ----------------- ----------------- ------------------- -------------------\n";
            }

            // Output the movie's details using the short listing function
            printShortMovieListing(current, outFile, count + 1);
            count++;
        }
        current = current -> next;
    }

    // Add Spacing after the search results
    outFile << "\n";

    if (count == 0) cout << "Sorry, no movies for the actor, " << actor << " were found.\n";
    else cout << "Found " << count << " movies for the actor " << actor << "!\n";
}

/*
 * yearSearch
 *
 * Searches the linked list for movies with the specified year and outputs each matching movie.
 *
 * @param head - Pointer to the head of the movie list
 * @param year - Year to search for
 * @param outFile - File stream for outputting results
 */
void yearSearch(Movie* head, const int year, ofstream &outFile) {
    Movie* current = head;  // INPUT - The current movie node being processed
    int count = 0;          // COUNTER & FLAG - Keeps track of the number of movies found

    while (current != nullptr) {
        if (current -> year == year) {
            // Output header only once, when the first match is found
            if (count == 0) {
                outFile << "\nSearch by year for " << year << " found:\n";
                outFile
                << "MOVIE # TITLE                                          YEAR RATING GENRE             ALT GENRE         LEAD ACTOR          SUPPORTING ACTOR\n"
                << "------- ---------------------------------------------- ---- ------ ----------------- ----------------- ------------------- -------------------\n";
            }

            // Output the movie's details using the short listing function
            printShortMovieListing(current, outFile, count + 1);
            count++;
        }
        current = current -> next;
    }

    // Add Spacing after the search results
    outFile << "\n";

    if (count == 0) cout << "Sorry, no movies for the year, " << year << " were found.\n";
    else cout << "Found " << count << " movies for the year " << year << "!\n";
}

/*
 * ratingSearch
 *
 * Searches the linked list for movies with the specified rating and outputs each matching movie.
 *
 * @param head - Pointer to the head of the movie list
 * @param rating - Rating to search for
 * @param outFile - File stream for outputting results
 */
void ratingSearch(Movie* head, int rating, ofstream &outFile) {
    Movie* current = head;  // INPUT - The current movie node being processed
    int count = 0;          // COUNTER & FLAG - Keeps track of the number of movies found

    while (current != nullptr) {
        if (current -> rating == rating) {
            // Output header only once, when the first match is found
            if (count == 0) {
                outFile << "\nSearch by rating for " << rating << " found:\n";
                outFile
                << "MOVIE # TITLE                                          YEAR RATING GENRE             ALT GENRE         LEAD ACTOR          SUPPORTING ACTOR\n"
                << "------- ---------------------------------------------- ---- ------ ----------------- ----------------- ------------------- -------------------\n";
            }

            // Output the movie's details using the short listing function
            printShortMovieListing(current, outFile, count + 1);
            count++;
        }
        current = current -> next;
    }

    // Add Spacing after the search results
    outFile << "\n";

    if (count == 0) cout << "Sorry, no movies for the rating, " << rating << " were found.\n";
    else cout << "Found " << count << " movies for the rating " << rating << "!\n";
}