CFLAGS=-c -g
LIB=trie.o

all: compile 

compile: scramble.c
	gcc $(CFLAGS) -o $(LIB) trie.c
	gcc -g -o scramble scramble.c
	gcc -g -o test test.c
	@echo Hey brudda.

clean:
	rm -f *~ $(LIB) 
	rm -f *~ scramble

test:
	gcc -ansi -lm -o unit_test unit_test.c
