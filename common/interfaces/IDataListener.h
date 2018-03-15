#ifndef IDATALISTENER_INCLUDED
#define IDATALISTENER_INCLUDED
#include <memory>
namespace Interfaces
{
    namespace Photosophus
    {
        template <typename T>
        struct  IDataListener
        {
            virtual void update (std::shared_ptr <T> data) = 0;
        };
    }
}
#endif // IDATALISTENER_INCLUDED
