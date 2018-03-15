OBJS = GraphPathCount.o MatrixHelper.o TestDetectBreach.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

countPath : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o countPath

GraphPathCount.o : GraphPathCount.cpp
	$(CC) $(CFLAGS) GraphPathCount.cpp

MatrixHelper.o : MatrixHelper.cpp
	$(CC) $(CFLAGS) MatrixHelper.cpp

TestDetectBreach.o :  TestDetectBreach.cpp
	$(CC) $(CFLAGS) TestDetectBreach.cpp


clean:
	rm *.o 

tar:
	tar cfv graphPathCount.tar util.h GraphPathCount.cpp  MatrixHelper.cpp MatrixHelper.h TestDetectBreach.h TestDetectBreach.cpp Makefile
