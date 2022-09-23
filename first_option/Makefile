all: 
	compile run clean

compile: main.c
	gcc -o main.o main.c -lm

run: main.o
	./main.o

clean: main.o
	rm -f  main.o
