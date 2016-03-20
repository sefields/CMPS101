/*
Sam Fields
sefields

Hayden Platt
hplatt

List.c
*/
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv){
	FILE* input = fopen(argv[1], "r");
	long numCustomers;
	long numPurchases;
	fscanf(input, "%ld", &numCustomers);
	fscanf(input, "%ld", &numPurchases);
	ListHndl array[numCustomers];
	for (int i = 1; i < numCustomers; i++){
		array[i] = newList();
	}
	long nextNum;
	long customerID = 0;
	long wordCount = 0;
	while(fscanf(input, "%ld", &nextNum) != 0){
		//If we are on an odd wordCount, nextNum is a customerID
		if(wordCount%2 == 1){
			customerID = nextNum;
		} else if (wordCount%2 == 0) {
			insertAtBack(array[customerID], nextNum);
		}
		wordCount++;
	}
	
	for(int i = 1; i < numCustomers; i++){
		printList(stdout, array[i]);
		freeList(array[i]);
	}
}