#ifndef SOCKETCOMMON_H_INCLUDED
#define SOCKETCOMMON_H_INCLUDED

#ifdef linux
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <ctype.h>
    #include <netdb.h>
#define _BSD_SOURCE
#endif

#endif // SOCKETCOMMON_H_INCLUDED
