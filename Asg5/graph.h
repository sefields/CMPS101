// Sam Fields
// sefields
//
// Mitch Mastroni
// memastro
//
// graph.h
// Header file for the graph ADT
//

#include<stdio.h>
#include"list.h"

typedef struct graphStruct* graphHndl;

/*
newGraph
Pre: none
Post: returns a graphHndl that points to a new graph with n vertices.
      lastSource is initialized to -1.
*/
graphHndl newGraph(int n);


/*
getDistance
Pre:  'destination' must exist on G
Post: Returns the distance from G->lastSource to destination.
      Returns -1 if no path exists.
*/
int getDistance(graphHndl G, int destination);


/*
getSource
Pre: none
Post: Returns the last source that BFS was called on G with.
      Returns -1 if BFS has not been called on G yet.
 */
int getSource (graphHndl G);

/*
addEdge
Pre: 'from' and 'to' must exist on G
Post: 'to' is added to the adjacency list of 'from'
 */
void addEdge(graphHndl G, int from, int to);

/*
printGraph
Pre: none
Post: Prints a list of vertices on G and the adjacency lists of each.
 */
void printGraph(graphHndl G);

/*
BFS
Pre:none
Post: Performs Breadth-First Search on G and initializes G->colors,
      G->distances, and G->parents. Additionally, G->lastSource = source.
 */
void BFS(graphHndl G, int source);

/*
pathTo
Pre: G->lastSource != -1. That is, BFS has been run on G at least once.
Post: Returns the list of vertices that constitutes the shortest path from
      G->lastSource to destination.
 */
ListHndl pathTo(graphHndl G, int destination);

/*
freeGraph
Pre: G is a graphHndl which points to a graphStruct that was malloc'd in newGraph.
Post: Frees all memory used by G, including all adjacency lists.
 */
void freeGraph(graphHndl G);
