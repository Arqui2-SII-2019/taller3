OPO=main.o matriz44.o matrizFC.o 
LIB=../lib
INCLUDE=../include
FLAG1=-Wall -c -O3 -msse4 -msse
FLAG2=-Wall -o
CC=gcc

output.o: $(OPO)
		$(CC) $(OPO) $(FLAG2) ../bin/output 

matriz44.o: $(LIB)/matriz44.c $(INCLUDE)/matriz44.h
		$(CC) $(FLAG1) ../lib/matriz44.c

matrizFC.o: $(LIB)/matrizFC.c $(INCLUDE)/matrizFC.h
		$(CC) $(FLAG1) ../lib/matrizFC.c
		
main.o: main.c
		$(CC) $(FLAG1) main.c 