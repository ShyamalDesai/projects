#ifndef LINUXSOCKETHANDLER_H
#define LINUXSOCKETHANDLER_H
#include <sys/epoll.h>

class LinuxSocketHandler
{
    public:
        LinuxSocketHandler(int size = 10);
        virtual ~LinuxSocketHandler();
        bool addSocketDescriptor (int sd, uint32_t eventsToMonitor=EPOLLIN);
        bool removeSocketDescriptor (int sd);
    protected:

    private:
        int _epollInstance;
        int _count;

};

#endif // LINUXSOCKETHANDLER_H
