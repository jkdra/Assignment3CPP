//
// Created by Jawad Khadra on 10/16/24.
//

#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// Struct for a movie object
struct Movie {
    string title;
    string lead;
    string supporting;
    string genre;
    string altGenre;
    int year;
    float rating;
    string synopsis;
    Movie* next;
};

/*
 * printHeadingConsole & printHeadingFile
 *
 * print the heading of the lab
 *
 * @return void
 */
void printHeadingConsole();
void printHeadingFile(ofstream &outFile);

/*
 * showDVDMenu
 *
 * show the menu for the assignment
 *
 * @return void
 */
void showDVDMenu();

/*
 * fileSetup
 *
 * allow the user to specify an input and output files. Allow the user the option to use a default file.
 *
 * @param inFile
 * @param outFile
 */
void fileSetup(fstream &inFile, fstream &outFile);

/*
 * createLinkedList
 *
 * create a linked list of movies from the input file
 *
 * @param inFile
 * @return
 */
Movie* createLinkedList(fstream &inFile);

/*
 * searchLinkedList
 *
 * search the linked list for a movie with the given title
 *
 * @param movieList
 * @param title
 * @return
 */
Movie* searchLinkedList(Movie* movieList, string title);

/*
 * printLinkedList
 *
 * print the linked list to the output file
 *
 * @param movieList
 * @param outFile
 */
void printLinkedList(Movie* movieList, fstream &outFile);

#endif //HEADER_H
