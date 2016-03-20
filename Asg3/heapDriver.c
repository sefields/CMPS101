// Sam Fields sefields
//
// NAME
//   heapDriver
//
// DESCRIPTION
//   Driver program for heap. Yo.
//   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "heap.h"

int main (int argc, char **argv) {

  //If there is an input file, open and use it
  if (argv[1]!=NULL) {
  char* progname = argv[0];
  FILE* input = fopen(argv[1],"r");
  int numKeys;
  int nextNum;
  fscanf(input,"%d",&numKeys);
  int keys[numKeys+1];
  keys[0] = 0;
  for (int i = 1; i <= numKeys+1 ; i ++) {
    fscanf(input,"%d",&nextNum);
    keys[i] = nextNum;
  } 
  heapHndl heapy = buildHeap(numKeys,keys,numKeys);
  printHeap(heapy);
  }
  else printf("No input file specified.\n");


  /* old testing code that seg faults:
  int array[] = {0,2,9,4,3,8};
  heapHndl heapy = buildHeap(100,array,6);
  printHeap(heapy);
  maxHeapify(heapy,1);
  printHeap(heapy);
  insert(heapy, 5);
  printHeap(heapy);
  printf("\nEND PROGRAM");*/

  return 0;
}
