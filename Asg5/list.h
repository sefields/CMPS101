// Originally created for CMPS 101 Prog 2 by:
// Sam Fields sefields
// Hayden Platt hplatt
//
// Adapted for CMPS 101 Prog 5 by:
// Sam Fields sefields
// Mitch Mastroni memastro
//
// CS 101 Prog 2
// List.h


#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
typedef struct ListStruct* ListHndl;
typedef struct NodeStruct* NodePtr;

ListHndl newList();
void freeList(ListHndl L);


//Access Functions
int getData(NodePtr N);
NodePtr nextNode(NodePtr N);
NodePtr firstNode(ListHndl L);
int isEmpty(ListHndl L);
int offEnd(ListHndl L);
int atFirst(ListHndl L);
int atLast(ListHndl L);
int getFirst(ListHndl L);
int getLast(ListHndl L);
int getCurrent(ListHndl L);

//Manipulation Procedures
void makeEmpty(ListHndl L);
void moveFirst(ListHndl L);
void moveLast(ListHndl L);
void movePrev(ListHndl L);
void moveNext(ListHndl L);
void insertAtFront(ListHndl L, int data);
void insertAtBack(ListHndl L, int data);
void insertBeforeCurrent(ListHndl L, int data);
void deleteFirst(ListHndl L);
void deleteLast(ListHndl L);
void deleteCurrent(ListHndl L);

//Other Operations
void printList(FILE* out, ListHndl L);
