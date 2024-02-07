CC = gcc
AR = ar
CFL = -Wall -g
LFL = rcs
.PHONY: all clean

all: my_graph my_Knapsack

my_graph: my_graph.o libmymat.a
	$(CC) $(CFL) $^ -o $@

my_Knapsack: my_Knapsack.o
	$(CC) $(CFL) $^ -o $@

my_knapsack.o: my_Knapsack.c
	$(CC) $(CFL) -c $<

my_graph.o:my_graph.c my_mat.h
	$(CC) $(CFL) -c $<

libmymat.a: my_mat.o
	$(AR) $(LFL) $@ $<

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFL) -c $<


clean:
	rm -f *.o *.a my_graph my_Knapsack


