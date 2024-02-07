all:connections prog
prog: my_Knapsack.o
	gcc -o prog my_Knapsack.o
connections: my_graph.o mylib.a
	gcc -o connections my_graph.o mylib.a

mylib.a: my_mat.o my_mat.h
	ar -rcs mylib.a my_mat.o

my_Knapsack.o:my_Knapsack.c
	gcc -c -Wall my_Knapsack.c -o my_Knapsack.o

my_graph.o:my_graph.c my_mat.h
	gcc -c -Wall my_graph.c -o my_graph.o

my_mat.o:my_mat.c my_mat.h
	gcc -c -Wall my_mat.c -o my_mat.o

.PHONY: clean

clean:
	rm -f *.o *.a *.so connections prog
