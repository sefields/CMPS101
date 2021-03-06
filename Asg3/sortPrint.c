// Sam Fields sefields
//
// NAME
//   sortPrint
//
// DESCRIPTION
//   Main program to test sorting algorithms. Dag.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

  //Test heapSort
  printf("\nTesting heapSort:\n");
  heapHndl H = buildHeap(numKeys,heapKeys,numKeys);
  heapKeys = heapSort(H,heapKeys,numKeys);
  printHeapArr(heapKeys,numKeys);

  //Verify that the heapKeys are sorted correctly
  int errors = 0;
  for (int i = 1; i <= numKeys-1; i++) {
    if (heapKeys[i] > heapKeys[i+1]) errors++;
  }
  if (errors ==0) printf("\nHeap Sort successful.\n");
  else {
    fprintf(stderr,"\nHeap Sort unsuccessful with %d errors.\n",errors);
  }

  //Test insertionSort
  printf("\nTesting insertionSort:\n");
  insertionSort(insertionKeys,numKeys);
  printArray(insertionKeys,numKeys);

  //Verify that the insertionKeys are sorted correctly
  errors = 0;
  for (int i = 0; i < numKeys-1; i++) {
    if (insertionKeys[i] > insertionKeys[i+1]) errors++;
  }
  if (errors ==0) printf("\nInsertion Sort successful.\n");
  else {
    fprintf(stderr,"\nInsertion Sort unsuccessful with %d errors.\n",errors);
  }

  }
  else {
    printf("No input file specified.\n");
    return 1;
  }
  return 0;
}
