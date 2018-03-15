#include "Connector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
    Connector::Connector(const std::string& host,
                        const uint16_t serverPortNum,
                        const int type,
                        const uint16_t clientPortNum)
                        : _cfd(0)
                        , _host(host)
                        , _srvPort(serverPortNum)
                        , _clientPort(clientPortNum)
                        , _type (type)
    {

    }

    Connector::~Connector()
    {
    }

    int
    Connector::connect ()
    {
        struct addrinfo hints;
        struct addrinfo *results;

        memset (&hints, 0, sizeof (struct addrinfo));
        hints.ai_canonname = NULL;
        hints.ai_family = AF_UNSPEC;
        hints.ai_addr = NULL;
        hints.ai_next = NULL;
        hints.ai_socktype = _type;
        char service_s [64];
        //::itoa (_portNum, service_s, 10);
        snprintf(service_s, sizeof(service_s), "%d",_srvPort);
        int s = getaddrinfo(_host.c_str(), service_s, &hints, &results);

        if (_cfd != 0)
        {
            errno  = ENOSYS;
            return -1;
        }

        struct addrinfo *rp = NULL;
        for (rp = results; rp != NULL; rp = rp->ai_next)
        {
            _cfd = socket (rp->ai_family, rp->ai_socktype, rp->ai_protocol);
            if (_cfd == -1)
                continue;

            if (::connect (_cfd, rp->ai_addr, rp->ai_addrlen) != -1)
                break;

            close (_cfd);
        }

        freeaddrinfo(results);

        return (rp == NULL)? -1 : 0;
    }

    void Connector::start()
    {

        while (true){ break;}
    }

    void Connector::stop ()
    {
    }


