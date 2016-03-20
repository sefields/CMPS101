// Sam Fields sefields
//
// NAME
//   decToBinary
//
// DESCRIPTION
//   Reads in a single non-negative decimal integer
//   from standard input and converts the number to
//   its binary representation
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "intstack.h"
#include "myinclude.h"

void toBinary (int input) {
  StackHndl binStack;
  binStack = NewStack();
  if (input == 0) Push(binStack, 0);
  while (input >0) {
    if (input%2 != 0) Push(binStack, 1);
    else Push(binStack, 0);
    input = input / 2;
  }
  while (!IsEmpty(binStack)) {
    printf("%d",Top(binStack));
    Pop(binStack);
  }
}

int main (int argc, char **argv) {
  printf("%s\n","Input a non-negative decimal integer to convert to binary:");
  int input = 0;
  int success = scanf("%d",&input);
  if (success != 1 || input<0) {
    printf("ERROR. Argument is not a non-negative decimal integer.\n");
    return 1;
  }
  printf("Decimal %d is ", input);
  toBinary(input);
  printf(" in binary.\n");
  return 0;
}
