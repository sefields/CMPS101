/*
List ADT originally written for CMPS 101 Prog 2 by:
Sam Fields
sefields
Hayden Platt
hplatt

Adapted for CMPS101 Prog 5 by:
Sam Fields
sefields
Mitch Mastroni
memastro

List.c
*/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct {
	int data;
	struct NodeStruct* next;
	struct NodeStruct* prev;
} NodeStruct;

typedef struct ListStruct {
	NodePtr first;
	NodePtr last;
	NodePtr current;
} ListStruct;

/* Constructor */
ListHndl newList(void){
	ListHndl this = malloc(sizeof(ListStruct));
	assert (this!=NULL);
	this->first = NULL;
	this->last = NULL;
	this->current = NULL;
	return this;
}

NodePtr newNode(void) {
        NodePtr this = malloc(sizeof(NodeStruct));
        assert(this!=NULL);
        this->data = 0;
        this ->next =NULL;
        this->prev =NULL;
        return this;
}

/* Access functions */
NodePtr nextNode(NodePtr N) {
  return N->next;
}

int getData(NodePtr N) {
  return N->data;
}

NodePtr firstNode(ListHndl L) {
  return L->first;
}

int isEmpty(ListHndl L){
	if(L->first == NULL){return 1;}
	else {return 0;}
}

int offEnd(ListHndl L){
	if(L->current == NULL){return 1;}
	else {return 0;}
}

int atFirst(ListHndl L){
	if(L->current == L->first && !offEnd(L)){return 1;}
	else {return 0;}
}

int atLast(ListHndl L){
	if(L->current == L->last && !offEnd(L)){return 1;}
	else {return 0;}
}

int getFirst(ListHndl L){
	assert(!isEmpty(L));
        return L->first->data;
}

int getLast(ListHndl L){
	assert(!isEmpty(L));
        return L->last->data;
}

int getCurrent(ListHndl L){
	assert(L->current != NULL);
	assert(!offEnd(L));
        return L->current->data;
}

/* Manipulation procedures */
void makeEmpty(ListHndl L){
	while (!isEmpty(L)) {
	deleteFirst(L);	
	}
}

void moveFirst(ListHndl L){
	assert(!isEmpty(L));
	L->current = L->first;
}

void moveLast(ListHndl L){
	L->current = L->last;
}

void movePrev(ListHndl L){
	L->current = L->current->prev;
}

void moveNext(ListHndl L){
	L->current = L->current->next;
}

void insertAtFront(ListHndl L, int data){
	NodePtr temp = malloc(sizeof(NodeStruct));
	temp->data = data;
	if(!isEmpty(L)){
	        L->first->prev = temp;
	        temp->next = L->first;
	} else {
		temp->next = NULL;
		L->last = temp;
	}
	L->first = temp;
}

void insertAtBack(ListHndl L, int data){ //cool
	NodePtr temp = newNode();
	temp->data = data;
	if(!isEmpty(L)){
	        L->last->next = temp;
	        temp->prev = L->last;
	} else {
		temp->prev = NULL;
		L->first = temp;
	}
	L->last = temp;
	temp->next = NULL;
}

void insertBeforeCurrent(ListHndl L, int data){
	NodePtr temp = malloc(sizeof(NodeStruct));
	temp->data = data;
	L->current->prev->next = temp;
	temp->prev = L->current->prev;
	temp->next = L->current;
	L->current->prev = temp;	
}

void deleteFirst(ListHndl L){
	assert(!isEmpty(L));
	NodePtr temp = L->first;
	//If there is a next node, now that one is first:
	if (L->first->next != NULL) L->first = L->first->next;
	else L->first = NULL;
	free(temp);
}

void deleteLast(ListHndl L){
	assert(!isEmpty(L));
	NodePtr temp = L->last;
	//If there is a second-to-last node, now it's last
	if (L->last->prev!=NULL) L->last = L->last->prev;
	free(temp);
}

void deleteCurrent(ListHndl L){
	assert(!isEmpty(L));
	NodePtr temp = L->current;
	NodePtr prevy = L->current->prev;
	NodePtr nexty = L->current->next;
	prevy->next = nexty;
	nexty->prev = prevy;
	free(temp);
	L->current = NULL;
}

/* Other operations */
void printList(FILE* out, ListHndl L){ //cool
  if (!isEmpty(L)){
	for (NodePtr c = L->first; c != NULL; c = c->next) {
		fprintf(out,"%d", c->data);
		if (c->next != NULL) printf(" -> ");
	}
  }
}

void freeList(ListHndl L){
	makeEmpty(L);
	free(L);
}
