OBJS = PhoneGen.o  KnightMoveGenerator.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LDFLAGS = -pthread  -Wall $(DEBUG)

genphno : $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o genphno

PhoneGen.o : PhoneGen.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) PhoneGen.cpp

KnightMoveGenerator.o : KnightMoveGenerator.cpp
	$(CC) $(CFLAGS) KnightMoveGenerator.cpp

clean:
	rm *.o 

tar:
	tar cfv PhoneGen.tar PhoneGen.cpp KnightMoveGenerator.cpp KnightMoveGenerator.h Algos.h PhoneNumberGenerator.h Makefile
