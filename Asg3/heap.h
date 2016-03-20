/*

Sam Fields
 
    Header (.h) file for the Heap ADT.
*/

#include<stdbool.h>
#include<stdio.h>

struct heapStruct;
typedef struct heapStruct* heapHndl;

/* newHeap creates a new heap object and returns a pointer to it.
   This should be used to initialize each heap before any other
   operations are performed on the heap. There is no precondition.
   The postcondition is that the stack is initialized to an empty
   stack.
*/

int* getData(heapHndl H);

heapHndl newHeap (int maxSize);

/* isFull returns true if a heap has reached its max size.
   Precondition: none
   Postcondition: Returns true if the heap is full, false otherwise.
*/

heapHndl buildHeap(int maxSize, int* data, int numData);

bool isFull(heapHndl H);

/* isEmpty
   Precondition: none
   Postcondition: returns true if the heap is empty, false otherwise.
*/

bool isEmpty(heapHndl H);

int maxValue(heapHndl H);

void deleteMax(heapHndl H);

void insert(heapHndl H, int priority);

void printHeap(heapHndl H);

void maxHeapify(heapHndl H, int i);
