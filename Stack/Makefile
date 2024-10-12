CC=g++
CFLAGS=-c -Wall -DDEBUG

main.exe: main.o Stack.o Checkout.o
	$(CC) main.o Stack.o Checkout.o -o main.exe

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Stack.o: Stack.cpp
	$(CC) $(CFLAGS) Stack.cpp

Checkout.o: Checkout.cpp
	$(CC) $(CFLAGS) Checkout.cpp


.PHONY: run
run:
	./main.exe Log.txt
