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
