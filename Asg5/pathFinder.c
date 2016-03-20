/*  
 *  CMPS 101 - Program 5
 *	Giving Directions
 *  Coded by
 *  Mitch Mastroni, memastro@ucsc.edu
 *  Sam Fields, sefields@ucsc.edu
 *  
 *  
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "graph.h"
 
 int main (int argc, char** argv){
   //printf ("argc: %d\n", argc);
   //printf ("argv: [0] = %s\n", argv[0]);
/* check for correct number of input files */
 	if (argc != 2){
		printf("Rerun with one input file.\n");
		printf("Exiting...\n");
		return 1;
	}
/* setup basic variables */
 int i, numVerts, numQueries;

/* open file */
	FILE *input = fopen (argv[1], "r");
/* check for errors */
    if (input == NULL) {
		fprintf(stderr, "Invalid file name, exiting.\n");
		exit(1);
    }

/* set first number to numVerts */
	fscanf(input, "%d", &numVerts);
/* set second number to numQueries */
	fscanf(input, "%d", &numQueries);
/* create Graph G with size numVerts */
	graphHndl G = newGraph (numVerts);
	
/* Build a directed graph, adding edges for each vertex  */
	for (i = 0; i < numVerts; i++){
	/* check that we're at the correct index */
		int vertLoader, j = 0;
		char buffer;
		fscanf(input, "%d", &vertLoader);
		if (i != vertLoader){
			printf ("Graph load index error.\n");
			printf ("Exiting...\n");
			return 1;
		}
		fscanf(input, "%c", &buffer);
	/* add edge FROM the current index TO the loaded vertex */
		while (buffer != '\n'){
			fscanf(input, "%d", &vertLoader);
			addEdge (G, i, vertLoader);
			fscanf(input, "%c", &buffer);
		}
	}
	
/* Find the path for numQueries vertex pairs, then print it out  */
	for (i = 0; i < numQueries; i++){
		int origin, destination, distance;
		fscanf(input, "%d", &origin);
	/* run BFS on G starting at origin */
		BFS (G, origin);
		fscanf(input, "%d", &destination);
	/* print path to destination */
		ListHndl list;
		distance = getDistance (G, destination);
		if (distance == -1){
		  printf ("No path from %d to %d exists.\n\n", origin, destination);
			break;
		}
                list = pathTo (G, destination);
		printf ("The shortest path from %d to %d requires %d edges:\n",
			origin, destination, distance);
		printList (stdout,list);
		freeList(list);
		printf ("\n\n");
	}
	freeGraph(G);
	fclose(input);
	return 0;
 }
