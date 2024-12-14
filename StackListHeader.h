//
// Created by Jawad Khadra on 12/10/24.
//

#ifndef STACKLISTHEADER_H
#define STACKLISTHEADER_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// Struct for a DVD node
struct DVDNode {
    string title;                 // stores the title of the movie
    string leadingActor;          // stores the name of the leading actor
    string supportingActor;       // stores the name of the supporting actor
    string genre;                 // stores the genre of the movie
    string alternateGenre;        // stores the alternative genre of the movie
    int year;                     // stores the year the movie was released
    int rating;                   // stores the rating of the movie
    string synopsis;              // stores the synopsis of the movie
    DVDNode* next;                // stores the next movie in the linked list
};

class StackList {
    public:

        // Constructor & Destructor
        StackList();
        ~StackList();

        // Mutators

        /*
         * push
         *
         * This method is used to push a DVD onto the stack
         */
        void Push(DVDNode newDVD);

        /*
         * pop
         *
         * This method is used to pop a DVD off the stack
         */
        void Pop();

        // Accessors
        bool IsEmpty() const;   // Check if the stack is empty
        DVDNode Peek() const;   // Peek at the top of the stack
        int size() const;       // Get the size of the stack

    protected:
        DVDNode* head;          // Pointer to the head of the stack
        int stackCount;         // Count of the number of elements in the stack
};

#endif //STACKLISTHEADER_H
