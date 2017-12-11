OBJS = PhoneGen.o  KnightMoveGenerator.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

genphno : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o genphno

PhoneGen.o : PhoneGen.cpp
	$(CC) $(CFLAGS) PhoneGen.cpp

KnightMoveGenerator.o : KnightMoveGenerator.cpp
	$(CC) $(CFLAGS) KnightMoveGenerator.cpp

clean:
	rm *.o 

tar:
	tar cfv PhoneGen.tar PhoneGen.cpp KnightMoveGenerator.cpp Alogs.h PhoneNumberGenerator.h Makefile
