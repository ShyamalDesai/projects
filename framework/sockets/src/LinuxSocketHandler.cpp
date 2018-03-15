#include "LinuxSocketHandler.h"
#include "../../../common/BaseUtil/LinuxErrorHelper.h"
#include <exception>
#include <unistd.h>
#include <errno.h>
#include <stdexcept>

LinuxSocketHandler::LinuxSocketHandler(int size)
: _count(0)
{
    _epollInstance = epoll_create(size);
    if (_epollInstance == -1)
    {
        //throw exception
        throw std::runtime_error (" epoll_create failed: desc " + Util::Photosophus::LinuxErrorHelper::GetErrorDescription(errno));
    }
}

//-----------------------------------------------------------------------
bool
LinuxSocketHandler::addSocketDescriptor (int sd, uint32_t eventsToMonitor)
{
    bool bRet(false);
    struct epoll_event evt;

    evt.events  = eventsToMonitor;
    evt.data.fd = sd;

    int ret = epoll_ctl(_epollInstance, EPOLL_CTL_ADD, sd, &evt);
    if (ret != 1)
    {
        bRet = true;
        ++_count;
    }
    return bRet;
}
//-----------------------------------------------------------------------

bool
LinuxSocketHandler::removeSocketDescriptor (int sd)
{
    bool bRet = false;

    int ret = epoll_ctl(_epollInstance, EPOLL_CTL_DEL, sd, NULL);
    if (ret != 1)
        bRet = true;
    else
    {
        //handel/log error ENOENT;
        --_count;
    }
    return bRet;
}
//-----------------------------------------------------------------------

LinuxSocketHandler::~LinuxSocketHandler()
{
    //dtor
    try
    {
        close (_epollInstance);
    }catch (...)
    {
    }
}
//-----------------------------------------------------------------------
