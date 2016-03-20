//Sam Fields
//sefields
//
//Mitch Mastroni
//memastro
//
// This program will test drive the graph ADT yo.
// 

#include"graph.h"

int main (int argc, char** argv) {
  argc = argc;
  argv = argv;

  //Build the graph
  graphHndl graphy = newGraph(10);
  addEdge(graphy, 0, 8);
  addEdge(graphy, 1, 7);
  addEdge(graphy, 4, 3);
  addEdge(graphy, 4, 2);
  addEdge(graphy, 4, 5);
  addEdge(graphy, 5, 0);

  //Print the graph
  printf("\nThis is the graph the program has been given:\n");
  printGraph(graphy);

  //Breadth-first search. getDistance test. pathTo test.
  printf("\nTesting BFS:\n");
  BFS(graphy, 4);
  int destination = 8;
  int distance = getDistance(graphy, destination);
  printf("\ngetDistance: The shortest path from vertex %d to vertex %d has distance %d\n",
	 getSource(graphy), destination, distance);
  ListHndl path = pathTo(graphy, 8);
  printf("\npathTo: The shortest path from vertex %d to vertex %d is as follows:\n",
	 getSource(graphy), destination);
  printList(stdout,path);
}
