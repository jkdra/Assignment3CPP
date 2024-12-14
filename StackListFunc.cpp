//
// Created by Jawad Khadra on 12/12/24.
//

#include "StackListHeader.h"

using namespace std;

// Constructor & Destructor
StackList::StackList() {
    head = nullptr;
    stackCount = 0;
}

StackList::~StackList() {
    DVDNode* current = head;
    DVDNode* next;

    while (current != nullptr) {
        next = current -> next;
        delete current;
        current = next;
    }
}

/*
 * Push
 *
 * This method is used to push a DVD onto the stack
 */
void StackList::Push(DVDNode newDVD) {
    newDVD.next = head;
    head = &newDVD;
}

/*
 * Pop
 *
 * This method is used to pop a DVD off the stack
 */
void StackList::Pop() {
    DVDNode* current = head;
    head = head -> next;
    delete current;
}

/*
 * IsEmpty
 *
 * Check if the stack is empty
 */
bool StackList::IsEmpty() const { return head == nullptr; }

/*
 * Peek
 *
 * Return the top of the stack
 */
DVDNode StackList::Peek() const { return *head; }

/*
 * Size
 *
 * Get the size of the stack
 */
int StackList::size() const { return stackCount; }
