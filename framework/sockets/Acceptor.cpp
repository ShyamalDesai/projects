#include "Acceptor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
namespace Framework
{
    namespace Photosophus
    {

    //if only port number is given, then call createsocket, bind and listen
        Acceptor::Acceptor(const uint16_t portNum, const int socktype )
            : _portNum (portNum)
        , _lfd(0)
        , _cfd(0)
        {
            listen (socktype);
        }


        Acceptor::~Acceptor()
        {
            //dtor
        }

        void
        Acceptor::registerDataListener   (Interfaces::Photosophus::IDataListener<char> *pDataListener)
        {
            _listeners.insert (pDataListener);
        }


        void
        Acceptor::deregisterDataListener (Interfaces::Photosophus::IDataListener<char> *pDataListener)
        {
            auto itr = _listeners.find (pDataListener);
            if (itr != _listeners.end())
                _listeners.erase(itr);

        }

        int Acceptor::createSocket (int family, int type)
        {
            int sd = socket (family, type, 0);
            return sd;
        }
        //if listen is called directly
        int
        Acceptor::listen(int type )
        {
            int iRet (-1);
            struct addrinfo hints;
            struct addrinfo * results = NULL;

            ::memset (&hints, 0, sizeof (struct addrinfo));
            hints.ai_canonname = NULL;
            hints.ai_addr = NULL;
            hints.ai_next = NULL;
            hints.ai_socktype = type;
            hints.ai_family = AF_UNSPEC;
            hints.ai_flags =AI_PASSIVE | AI_NUMERICSERV;
            char service_s [64];
            //::itoa (_portNum, service_s, 10);
            snprintf(service_s, sizeof(service_s), "%d",_portNum);
            if (getaddrinfo( NULL, service_s, &hints, &results) != 0)
            {

                std::cout << "Acceptor::bind::getaddrinfo failed with errno " << errno << std::endl;
                //error
                //log
                //return error code
            }

            //walk through the returned list until we find an address structure that can be used to successfully create and bind a socket
            int optval = 1;
            struct addrinfo * rp = NULL;
            for (rp = results; rp != NULL; rp = rp->ai_next)
            {
                _lfd = createSocket (rp->ai_family);
                if (_lfd == -1)
                    continue;


                if (setsockopt(_lfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof (optval)) == -1)
                {
                    std::cout << "Error in setting socket options" << std::endl;

                }

                if (bind (_lfd, rp->ai_addr, rp->ai_addrlen) == 0)
                {
                    if (rp->ai_canonname)
                    std::cout << " listening on " << rp->ai_canonname << std::endl;
                    break;
                }
                ::close (_lfd);
            }
            if (_lfd)
            {
                if (::listen (_lfd, 10) == -1)
                {
                    std::cout << "listen failed " << std::endl;
                }


                iRet = 0;
            }
            freeaddrinfo(results);
            return iRet;
        }
    }
}
