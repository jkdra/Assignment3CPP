/*
* AUTHOR : Jawad Khadra
 * STUDENT ID : 1312092 (IVC)
 * ASSIGNMENT #3
 * CLASS : CS1B
 * SECTION : MW: 7:30p - 9:50p
 * DUE DATE : Oct. 28, 2024
 */

#include "header.h"

using namespace std;

/*
 * Assignment 3: Searching Linked Lists
 *
 * This program allows the user to track and search their DVDs
 */

// main
int main() {

    Movie* movieList = nullptr;       // OUTPUT - Pointer to the head of the movie list
    MENU_OPTIONS menuSelection;       // INPUT - Menu Selection
    string title;            // INPUT - Title of the movie
    string genre;            // INPUT - Genre of the movie
    string actor;            // INPUT - Actor of the movie
    int year;                // INPUT - Year of the movie
    float rating;            // INPUT - Rating of the movie

    // Print the heading of the lab
    printHeadingConsole();

    // Initialize the input and output files
    ofstream outFile;
    fileSetup(outFile, movieList);


    do {
        // Show the menu
        showDVDMenu();
        // Get the menu selection
        // Invalid Input Check
        if (cin.fail()) {
            cerr << "\nPlease input a number between 0 and 6\n";
            cin.clear();
            cin.ignore();
            continue;
        }
        // Clear the input buffer
        cin.clear();
        cin.ignore();
        switch (menuSelection) {
            default:
                cout
                << "\n**** The number " << menuSelection << " is an invalid entry      ****\n"
                << "**** Please input a number between 0 and 6 ****\n";
                break;
            case 0:
                // Don't do anything, the loop will recognize 0 already and exit successfully.
                break;
            case 1:
                break;
            case 2:
                break;
        }
    } while (menuSelection != 0);

    return 0;
}
