#ifndef ACCEPTOR_H
#define ACCEPTOR_H
#include "SocketCommon.h"
#include "../../common/interfaces/IAMDataPublisher.h"
#include "../../common/interfaces/IDataListener.h"
#include <set>

namespace Framework
{
    namespace Photosophus
    {
        class Acceptor : public Interfaces::Photosophus::IAMDataPublisher <char>
        {
            public:
                Acceptor(const uint16_t portNum, const int socktype=SOCK_STREAM);
                virtual ~Acceptor();

                void registerDataListener   (Interfaces::Photosophus::IDataListener<char> *pDataListener);
                void deregisterDataListener (Interfaces::Photosophus::IDataListener<char> *pDataListener);
                void start();
                void stop ();

                int  listen(int socktype = SOCK_STREAM);
                int createSocket (int family, int type = SOCK_STREAM);


            protected:

            private:
            int     _portNum;
            int     _lfd;
            int     _cfd;
            std::set<Interfaces::Photosophus::IDataListener<char> *> _listeners;
        };
    }
}
#endif // ACCEPTOR_H
