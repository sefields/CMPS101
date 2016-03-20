# Sam Fields sefields
# Makefile for Asg3 - by DPH, modified Spring 2014
# It compiles the module and creates the intstackdr executable

all : heapDriver sortPrint sortComp

#HEAP DRIVER
heapDriver: heapDriver.o heap.o heapSort.o
	gcc -std=c99 -Wall -Wextra -pedantic -o heapDriver heapDriver.o heap.o heapSort.o

#SORT PRINT EX
sortPrint : sortPrint.o insertionSort.o heapSort.o heap.o
	gcc -std=c99 -Wall -Wextra -pedantic -o sortPrint sortPrint.o insertionSort.o heapSort.o heap.o

#SORT COMP EX
sortComp : sortComp.o insertionSort.o heapSort.o heap.o
	gcc -std=c99 -Wall -Wextra -pedantic -o sortComp sortComp.o insertionSort.o heapSort.o heap.o

#HEAP
heap.o: heap.h heap.c
	gcc -c -std=c99 -Wall -Wextra -pedantic heap.c

heapDriver.o: heap.h heapDriver.c
	gcc -c -std=c99 -Wall -Wextra -pedantic heapDriver.c

#INSERTION SORT
insertionSort.o : insertionSort.h insertionSort.c
	gcc -c -std=c99 -Wall -Wextra -pedantic insertionSort.c

#SORT PRINT AND SORT COMP
sortPrint.o : insertionSort.h heapSort.h sortPrint.c
	gcc -c -std=c99 -Wall -Wextra -pedantic sortPrint.c

sortComp.o : insertionSort.h heapSort.h sortComp.c
	gcc -c -std=c99 -Wall -Wextra -pedantic sortComp.c

#HEAP SORT
heapSort.o : heapSort.h heapSort.c
	 gcc -c -std=c99 -Wall -Wextra -pedantic heapSort.c

#CLEAN
clean :
	rm heapDriver sortPrint heap.o heapDriver.o insertionSort.o sortPrint.o heapSort.o

# an old version of the makefile used the additional gcc option
# -I/usr/lang/SC1.0/ansi_include but it is not needed on my system
# we should double check that that option is not needed on the cats system