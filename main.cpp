/*
* AUTHOR : Jawad Khadra
 * STUDENT ID : 1312092 (IVC)
 * ASSIGNMENT #5 - DVD Movie List (Intro to OOP)
 * CLASS : CS1B
 * SECTION : MW: 7:30p - 9:50p
 * DUE DATE : Dec. 13, 2024
 */

#include "header.h"

using namespace std;

/*
 * Assignment 5: Intro to Object-Oriented Programming (DVD Movie List)
 *
 * This program allows the user to track and search their DVDs through object-oriented programming.
 */

// main
int main() {
    MovieList* movieList = new MovieList();  // DATA - Pointer to the linked list head
    string inputFileName, outputFileName;    // INPUT - Stores the user's input and output file names


    // Print the heading of the lab to the console
    printHeadingConsole();

    // Setup input and output files, and populate the linked list
    cout << "\nWhich input file would you like to use?\n";
    getline(cin, inputFileName);

    cout << "\nWhich output file would you like to use?\n";
    getline(cin, outputFileName);

    movieList->CreateList(inputFileName);
    movieList->OutputList(outputFileName);


    return 0;
}