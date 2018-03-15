#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "SocketCommon.h"
#include <string>
class Connector
{
    public:
        Connector(const std::string& host,
                const uint16_t serverPortNum,
                const int type = SOCK_STREAM,
                const uint16_t clientPortNum=0);
        virtual ~Connector();
        int connect ();
        void start();
        void stop ();

    protected:

    private:
        int _cfd;
        std::string _host;
        uint16_t    _srvPort;
        uint16_t    _clientPort;
        int         _type;

};

#endif // CONNECTOR_H
