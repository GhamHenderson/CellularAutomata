CC=gcc

cellautochild.o: cellautochild.c
	$(CC) -c cellautochild.c

cellautoMain: cellautoMain.c cellautoMain.o cellautochild.o functions.h
	$(CC) -o output cellautoMain.c cellautochild.c -lpthread


clean: *.o
	rm -f *.o
	rm -f myStats
