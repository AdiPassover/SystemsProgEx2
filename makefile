CC = gcc
AR = ar
CFL = -Wall -g
LFL = rcs
.PHONY: all clean

all: connections

connections: main.o libmymat.a
	$(CC) $(CFL) $^ -o $@

main.o:main.c my_mat.h
	$(CC) $(CFL) -c $<

libmymat.a: my_mat.o
	$(AR) $(LFL) $@ $<

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFL) -c $<


clean:
	rm -f *.o *.a connections


