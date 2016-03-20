/*

Sam Fields

  heapSort.c

*/

#include <stdio.h>
#include <stdlib.h>
#include"heapSort.h"

/*int* heapSort(int keys[], int numKeys) {
  heapHndl H = newHeap(numKeys);
  int sortedA[numKeys];
  //Building the heap
  for (int j = 1; j <= numKeys; j++) {
    int x = keys[j];
    insert(H, x);
  }
  //Load array from bottom-right to top-left
  for (int i = numKeys; i >= 1; i--) {
    sortedA[i] = maxValue(H);
    deleteMax(H);
  }
  return sortedA;
  }*/

int* heapSort(heapHndl H, int keys[], int numKeys) {
  //Load array from bottom-right to top-left
  for (int i = numKeys; i >= 1; i--) {
    keys[i] = maxValue(H);
    deleteMax(H);
    }
  return keys;
}
