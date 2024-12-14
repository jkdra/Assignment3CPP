//
// Created by Jawad Khadra on 12/10/24.
//

#ifndef MOVIELISTHEADER_H
#define MOVIELISTHEADER_H

#include "StackListHeader.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class MovieList : public StackList {
    public:
        // Constructor & Destructor
        MovieList();
        ~MovieList();

        /*
         * CreateList
         *
         * This method is used to create a linked list of DVD nodes
         */
        void CreateList(string inputFileName);

        /*
         * OutputList
         *
         * This method is used to output the linked list of DVD nodes to a file
         */
        void OutputList(string outputFileName);

    private:
        static string WordWrap(string plot);                  // Wraps the plot of the movie to fit in a 75 character line
        static string TitleShortener(string title);           // Concatenates the title of the movie using ... (ellipsis)
        static void printClassHeader(string outputFileName);  // Prints the class header to the output file
};


#endif //MOVIELISTHEADER_H
