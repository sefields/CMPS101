//Sam Fields
//insertionSort.c

#include "insertionSort.h"

void insertionSort(int A[], int length) {
  int key;
  int i;
  for (int j = 0; j < length; j++) {
    key = A[j];
    i = j-1;
    while (i>=0 && A[i] > key) {
      A[i+1] = A[i];
      i = i-1;
    }
    A[i+1] = key;
  }
}
