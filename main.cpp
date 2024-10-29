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
    ofstream outFile;
    Movie* movieList = nullptr; // HEAD - Pointer to the linked list head
    int menuOptionInput;        // INPUT - Stores the user's menu choice

    printHeadingConsole();

    // Setup input and output files, and populate the linked list
    fileSetup(outFile, movieList);

    do {
        showDVDMenu();  // Show the menu
        cin >> menuOptionInput;
        cin.ignore();  // Clear newline left in the input buffer

        // Convert integer input to enum type for safety and clarity
        MENU_OPTIONS menuOption = static_cast<MENU_OPTIONS>(menuOptionInput);

        // Handle menu selection
        handleMenuSelection(menuOption, movieList, outFile);

    } while (menuOptionInput != EXIT);  // Loop until user enters EXIT (0)

    // Cleanup
    outFile.close();

    return 0;
}