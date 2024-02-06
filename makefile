CC = gcc
AR = ar
CFL = -Wall -g
LFL = rcs
.PHONY: all clean

all: my_graph my_Knapsack

my_graph: main.o libmymat.a
	$(CC) $(CFL) $^ -o $@

my_Knapsack: my_Knapsack.o
	$(CC) $(CFL) $^ -o $@

my_knapsack.o: my_Knapsack.c
	$(CC) %(CFL) -c $<

main.o:main.c my_mat.h
	$(CC) $(CFL) -c $<

libmymat.a: my_mat.o
	$(AR) $(LFL) $@ $<

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFL) -c $<


clean:
	rm -f *.o *.a connections


