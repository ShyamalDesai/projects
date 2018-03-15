OBJS = TickDB.o CTickRepository.o CTickRecord.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

TickDB : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o TickDB

CTickRecord.o : CTickRecord.cpp
	$(CC) $(CFLAGS) CTickRecord.cpp

CTickRepository.o : CTickRepository.cpp
	$(CC) $(CFLAGS) CTickRepository.cpp

CTickDB.o :  TickDB.cpp
	$(CC) $(CFLAGS) TickDB.cpp


clean:
	rm *.o 

tar:
	tar cfv TickDB.tar readme.txt Util.h CFieldList.h  CTickRecord.cpp CTickRecord.h CTickRepository.h CTickRepository.cpp tick1.txt TickDB.cpp Makefile
zip:    
	zip TickDb.zip	readme.txt Util.h CFieldList.h  CTickRecord.cpp CTickRecord.h CTickRepository.h CTickRepository.cpp tick1.txt TickDB.cpp Makefile

