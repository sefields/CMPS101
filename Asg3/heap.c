/* 

Sam Fields

This is heap.c, containing the definitions for the stuff in heap.h.
 */
#include "heap.h"
#include <stdlib.h>
#include <assert.h>

struct heapStruct {
  int maxSize;
  int currSize;
  int* data;
};

//Returns the index of the left child of a node
int leftChild(int index) {
  return 2*index;
}

//Returns the index of the right child of a node
int rightChild(int index) {
  return 2*index+1;
}

//Returns the index of the parent of a node
int parent(int index) {
  return index/2;
}

//Returns the data array associated with a heap
int* getData(heapHndl H) {
  return H->data;
}


/* newHeap creates a new heap object and returns a pointer to it.
   This should be used to initialize each heap before any other
   operations are performed on the heap. There is no precondition.
   The postcondition is that the heap array is initialized to an empty
   array.
*/


heapHndl newHeap (int maxSize) {
  heapHndl newHeap = malloc(sizeof(struct heapStruct));
  newHeap -> maxSize = maxSize;
  newHeap -> currSize = 0;
  newHeap -> data = malloc(maxSize*sizeof(int));
  return newHeap;
}

/* buildHeap creates a new heap object and returns a pointer to it.
   This should be used to initialize each heap before any other
   operations are performed on the heap. There is no precondition.
   The postcondition is that the heap array is initialized to the
   user's specified array.
 */

heapHndl buildHeap (int maxSize, int* array, int numData) {
  heapHndl nu = newHeap(maxSize);
  for (int i = 1; i <= numData; i++) {
    insert(nu, array[i]);
  }
  return nu;
}

/* isFull returns true if a heap has reached its max size.
   Precondition: none
   Postcondition: Returns true if the heap is full, false otherwise.
*/

bool isFull(heapHndl H) {
  return(H->currSize == H->maxSize);
}

/* isEmpty
   Precondition: none
   Postcondition: returns true if the heap is empty, false otherwise.
*/

bool isEmpty(heapHndl H) {
  return (H->currSize == 0);
}

/*
  fixProblem child is used to traverse upward through a heap from a
  specified index and fix instances where a child node has a higher
  value than its parent.
  Precondition: none
  Postcondition: the heap satisfies the heap property
 */
void fixProblemChild(heapHndl H, int i) {
  if (i == 1) return;//at root
  else {
    int p = parent(i);
    if (H->data[i] > H->data[p]) {
      //Swap A[i] and A[p]
      int tmp = H->data[i];
      H->data[i] = H->data[p];
      H->data[p] = tmp;
      fixProblemChild(H, p);
    }
    else return;
  }
}

/*
  maxValue returns the max value, assuming that a heap satisfies the 
  heap property.
  Precondition: the heap H satisfies the heap property.
  Postcondition: Returns the value in index 1, ostensibly the maximum value
  in the heap
 */

int maxValue(heapHndl H) {
  return H->data[1];
}

/*
  deleteMax
  Precondition: the heap satisfies the heap property, meaning the maximum
  value is in index 1.
  Postcondition: the heap still satisfies the heap property, but the previous
  maximum is gone and is now replaced by what was previously the 
  second-highest value
 */

void deleteMax(heapHndl H) {
  int tmp = H->data[1];
  H->data[1] = H->data[H->currSize];
  H->data[H->currSize] = tmp;
  H->currSize = H->currSize - 1;
  maxHeapify(H,1);
}

/*
  insert
  Precondition: the heap has not yet reached maxSize
  Postcondition: the heap's currSize increases by 1 and the user's
  specified key is now in the heap
 */

void insert(heapHndl H, int key) {
  assert(!isFull(H));
  H->currSize = H->currSize + 1;
  //printf("New size calculated\n");
  H->data[H->currSize] = key;
  fixProblemChild(H, H->currSize);

}

/*
  printHeap
  Created by me for debugging.
  PreCondition / Postcondition: none
 */

void printHeap(heapHndl H){
  printf("%s%d\n","The max size is ",H->maxSize);
  printf("%s%d\n","The current size is ",H->currSize);
  for (int i = 1; i <= H-> currSize; i++) {
    printf("At index %d ",i);
    printf("%d\n", H->data[i]);
  }
  printf("\n");
  return;
}

/*
  maxHeapify traverses the array downward from the given index and
  ensures that it satisfies the heap property.
  Precondition: the heap is not empty
  Postcondition: the heap now satisfies the heap property
 */

void maxHeapify(heapHndl H, int i){
  //printf("\n Max Heapify says the current heap is: \n");
  //printHeap(H);
  if (isEmpty(H)) return;
  int l = leftChild(i);
  int r = rightChild(i);
  int largest = 1;
  if (l <= H->currSize && H->data[l] > H->data[i]) largest = l;
  else largest = i;
  if (r <= H->currSize && H->data[r] > H->data[largest]) largest = r;
  if (largest != i) {
    int tmp = H->data[i];
    H->data[i] = H->data[largest];
    H->data[largest] = tmp;
    maxHeapify(H , largest);
  }
}
