#define LINEBREAK printf("\n"); 
#define PL printf

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode
{
    int value;
    struct ListNode *next;
    struct ListNode *prev;
} listNode;

// Prints the values stored in the list first to last.
void printListForward(listNode *head);


// Prints the values stored in the list last to first.
void printListBackward(listNode *tail);

// get list length.
int getLength(listNode *head);

// Checks memory address and exits program if invalid.
void isValidAddress(void *addr);

// delete list
void deleteList(listNode *head);

// Returns true if list is empty.
bool isEmpty(listNode *head);

// Pushes the given value onto the beginning of the list.
void pushFront(listNode **head, listNode **tail, int value);

// Remove first item in the list, returning its value.
int popFront(listNode **head, listNode **tail);

// Returns the value of the nth item
int valueAtIndex(listNode *head, int index);

// Adds an item at the end of the list.
void pushBack(listNode **head, listNode **tail, int value);

// Remove the last item in the list, returning its value.
int popBack(listNode **head, listNode **tail);

// Returns the value at the front of the list.
int front(listNode *head);

// Returns the value at the end of the list.
int back(listNode *tail);

void insert(listNode **head, listNode **tail, int index, int value);

// Removes node at given index (starts at 0, like array)
void erase(listNode **head, listNode **tail, int index);

int valueAtIndexFromEnd(listNode *tail,int index);

// Removes the first item in the list with this value
int removeValue(listNode **head, listNode **tail, int value);