//
// Created by Jawad Khadra on 10/16/24.
//

#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
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
    string plot;
    Movie* next;
};


enum MENU_OPTIONS {
    OUTPUT_LIST = 1,
    TITLE_SEARCH = 2,
    GENRE_SEARCH = 3,
    ACTOR_SEARCH = 4,
    YEAR_SEARCH = 5,
    RATING_SEARCH = 6,
    EXIT = 0
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
 * allow the user to specify an input and output files. Allow the user the option to use a default file. In the process, create a linked list of movies from the input file.
 *
 * @param inFile
 * @param outFile
 */
void fileSetup(ofstream &outFile, Movie *&movieList);

/*
 * formatPlot
 *
 * format the plot of the movie to fit in a 75 character line
 *
 * @param plot - Plot of the movie
 * @return string - Formatted plot
 */
string formatPlot(const string &plot);

/*
 * printLongMovieListing & printShortMovieListing
 *
 * print the movie listings to the output file
 *
 * printShort will print everything except the synopsis, ideal for multiple movies at a time.
 * printLong will print everything including the synopsis, but is only used for one movie at a time.
 *
 * @param movieList
 * @param outFile
 */
void printShortMovieListing(Movie* movieList, fstream &outFile);
void printLongMovieListing(Movie* movieList, fstream &outFile);

/*
 * titleSearch
 *
 * search the linked list for a movie with the given title
 *
 * @param movieList
 * @param title
 * @return
 */
void titleSearch(Movie* head, const string& title, fstream &outFile);

/*
 * genreSearch
 *
 * search the linked list for a movie with the given genre
 *
 * @param movieList
 * @param genre
 * @return
 */
void genreSearch(Movie* head, const string& genre, fstream &outFile);

/*
 * actorSearch
 *
 * search the linked list for a movie with the given actor
 *
 * @param movieList
 * @param actor
 * @return
 */
void actorSearch(Movie* head, const string& actor, fstream &outFile);

/*
 * yearSearch
 *
 * search the linked list for a movie with the given year
 *
 * @param movieList
 * @param year
 * @return
 */
void yearSearch(Movie* head, const int year, fstream &outFile);

/*
 * ratingSearch
 *
 * search the linked list for a movie with the given rating
 *
 * @param movieList
 * @param rating
 * @return
 */
void ratingSearch(Movie* head, const float rating, fstream &outFile);


#endif //HEADER_H
