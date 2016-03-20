// Sam Fields sefields
//
// NAME
//   sortComp
//
// DESCRIPTION
//   Main program to compare speeds of sorting algorithms.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "insertionSort.h"
#include "heapSort.h"

void printArray(int array[], int arrayLength) {
  for (int i = 0; i < arrayLength; i++) {
    printf("At index %d : ",i);
    printf("%d\n",array[i]);
  }
  printf("\n\n");
  return;
}

void printHeapArr(int array[], int arrayLength) {
  for (int i = 1; i <= arrayLength; i++) {
    printf("At index %d : ",i);
    printf("%d\n",array[i]);
  }
  printf("\n\n");
  return;
}

int main (int argc, char **argv) {

  //Start the clock
  clock_t startTime, duration;

  //Open and read the input file if it is specified
  if (argv[1]!=NULL) {
  char* progname = argv[0];
  FILE* input = fopen(argv[1],"r");
  int numKeys;
  int nextNum;
  fscanf(input,"%d",&numKeys);

  //Initialize an array for heapSort.
  //Because index 0 is unused in a heap,
  //initialize the array to have one extra
  //space. Set index 0 to 0.
  int* heapKeys = calloc(numKeys+1, sizeof(int));
  heapKeys[0] = 0;

  //Initialize another array for insertionSort
  int insertionKeys[numKeys];

  //Scan all the keys, store them in the two arrays
  for (int i = 1; i <= numKeys+1 ; i ++) {
    fscanf(input,"%d",&nextNum);
    heapKeys[i] = nextNum;
    insertionKeys[i-1] = nextNum;
  } 

  //Start the clock for heapSort
  startTime = clock();

  //Test heapSort
  printf("\nTesting heapSort:\n");
  heapHndl H = buildHeap(numKeys,heapKeys,numKeys);
  heapKeys = heapSort(H,heapKeys,numKeys);
  //printHeapArr(heapKeys,numKeys);

  //Stop the clock for heapSort, produce information
  duration = clock() - startTime;
  float realTime = (float)duration / CLOCKS_PER_SEC;
  printf("\nFor %d pieces of data, Heap Sort took %f time.\n",numKeys,realTime);

  //Start the clock for insertionSort
  startTime = clock();

  //Test insertionSort
  printf("\nTesting insertionSort:\n");
  insertionSort(insertionKeys,numKeys);
  //printArray(insertionKeys,numKeys);

  //Stop the clock for insertionSort, produce information
  duration = clock() - startTime;
  realTime = (float)duration / CLOCKS_PER_SEC;
  printf("\nFor %d pieces of data, Insertion Sort took %f time.\n",numKeys,realTime);

  }

  else {
    printf("No input file specified.\n");
    return 1;
  }
  return 0;
}
