# Sam Fields sefields
# Mitch Mastroni memastro
# Makefile for Prog5
# Creates graphDriver and pathFinder applications

all : graphDriver pathFinder

#PATH FINDER
pathFinder: pathFinder.o graph.o list.o
	gcc -std=c99 -Wall -Wextra -pedantic -o pathFinder pathFinder.o graph.o list.o

#GRAPH DRIVER
graphDriver: graphDriver.o graph.o list.o
	gcc -std=c99 -Wall -Wextra -pedantic -o graphDriver graphDriver.o graph.o list.o

#LIST
list.o: list.c
	gcc -c -std=c99 -Wall -Wextra -pedantic list.c

#PATH FINDER
pathFinder.o: pathFinder.c
	gcc -c -std=c99 -Wall -Wextra -pedantic pathFinder.c

#GRAPH
graph.o: graph.c
	gcc -c -std=c99 -Wall -Wextra -pedantic graph.c

graphDriver.o: graphDriver.c
	gcc -c -std=c99 -Wall -Wextra -pedantic graphDriver.c

#CLEAN
clean :
	rm graphDriver graph.o graphDriver.o list.o

# an old version of the makefile used the additional gcc option
# -I/usr/lang/SC1.0/ansi_include but it is not needed on my system
# we should double check that that option is not needed on the cats system