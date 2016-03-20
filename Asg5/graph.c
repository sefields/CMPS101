// Sam Fields
// sefields
//
// Mitch Mastroni
// memastro
//
// The definitions of the functions for the graph ADT outlined in graph.h
//

#include <stdlib.h>
#include <string.h>
#include "graph.h"

struct graphStruct {
  int numVertices;
  ListHndl vertices[10000];
  int lastSource;
  char* colors[10000];
  int distances[10000];
  int parents[10000];
} graphStruct;

graphHndl newGraph(int n) {
  graphHndl this = malloc(sizeof(graphStruct));
  //Initialize numVertices and vertices
  this->numVertices = n;
  for (int i = 0; i < this->numVertices ; i++) {
    this->vertices[i] = newList();
  }
  this->lastSource = -1;
  return this;
}

void addEdge(graphHndl G, int from, int to) {
  assert(from < G->numVertices && to < G->numVertices);
  insertAtBack(G->vertices[from],to);
}

void printGraph(graphHndl G) {
  printf("\n");
  for (int i = 0; i < G->numVertices ; i++ ) {
    printf("Vertex #%d has edges to the following vertices:\n", i);
    printList(stdout,G->vertices[i]);
    printf("\n");
  }
}

void BFS(graphHndl G, int source) {
  G->lastSource = source;
  //All vertices except source are white, infinite distance, null parents
  for (int i = 0; i < G->numVertices ; i++) {
    if (i != source) {
      G->colors[i] = "white";
      G->distances[i] = -1;
      G->parents[i] = -1;
    }
  }
  //Source color, distance, and parent set
  G->colors[source] = "gray";
  G->distances[source] = 0;
  G->parents[source] = -1;

  //Initialize queue containing only S
  ListHndl Q = newList();
  insertAtBack(Q, source);
  
  //Determine what vertex is at the head of Q. Remove it.
  while(!isEmpty(Q)) {
    int u = getFirst(Q);
    deleteFirst(Q);

    for (NodePtr curr = firstNode(G->vertices[u]) ; curr != NULL; curr = nextNode(curr)) {
      int v = getData(curr);
      if (strncmp(G->colors[v],"white",5)==0) {
	G->colors[v] = "gray";
	G->distances[v] = G->distances[u] +1;
	G->parents[v] = u;
	insertAtBack(Q,v);
      }
    }
    G->colors[u] = "black";
  }
  freeList(Q);

  /*
    DEBUG PRINT STATEMENT:
  printf("The source is %d\n",G->lastSource);
  for (int i = 0; i < G->numVertices ; i++) {
    printf("Vertex #%d has color %s, distance %d, parent %d\n"
	   ,i,G->colors[i],G->distances[i],G->parents[i]);
  }
  */
}

int getDistance(graphHndl G, int destination) {
  assert(destination < G->numVertices);
  return G->distances[destination]; //This will return -1 if there is no path
}

int getSource (graphHndl G) {
  return G->lastSource;
}

ListHndl pathTo(graphHndl G, int destination) {
  ListHndl L = newList(); //The list to be returned
  //Assuming that BFS has been run...
  assert(G->lastSource != -1);
  insertAtFront(L, destination);
  int temp = G->parents[destination];
  while (temp != -1) {
	insertAtFront(L,temp);
	temp = G->parents[temp];
      }
  return L;
}

void freeGraph(graphHndl G) {
  for (int i = 0; i < G->numVertices ; i++ ) {
    freeList(G->vertices[i]);
  }
  free(G);
}
