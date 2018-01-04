OBJS = findSubSequence.o TestSubSequence.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

findss : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o findss

findSubSequence.o : findSubSequence.cpp
	$(CC) $(CFLAGS) findSubSequence.cpp

TestSubSequence.o : Util.h TestSubSequence.cpp
	$(CC) $(CFLAGS) TestSubSequence.cpp


clean:
	rm *.o 

tar:
	tar cfv fseq.tar Util.h findSubSequence.cpp TestSubSequence.h TestSubSequence.cpp Makefile
