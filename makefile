all:prog
prog: main.o mylib.a
	gcc -o prog main.o mylib.a

mylib.a: my_mat.o my_mat.h
	ar -rcs mylib.a my_mat.o

main.o:main.c my_mat.h
	gcc -c -Wall main.c -o main.o

my_mat.o:my_mat.c my_mat.h
	gcc -c -Wall my_mat.c -o my_mat.o

.PHONY: clean

clean:
	rm -f *.o *.a *.so prog
