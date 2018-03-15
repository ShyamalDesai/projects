#ifndef IAMDATAPUBLISHER_H_INCLUDED
#define IAMDATAPUBLISHER_H_INCLUDED
#include "IDataListener.h"

namespace Interfaces
{
    namespace Photosophus
    {
        template <typename T>
        struct IAMDataPublisher
        {
            virtual void registerDataListener   (IDataListener<T> *pDataListener) = 0;
            virtual void deregisterDataListener (IDataListener<T> *pDataListener) = 0;
        };
    }
}

#endif // IAMDATAPUBLISHER_H_INCLUDED
