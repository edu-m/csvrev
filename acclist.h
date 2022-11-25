#include "list.h"
#include "node.h"
#include "accstat.h"
#include <fstream>

class AccStatList : public List<AccStat>
{
    unsigned short diplaySize;

public:
    unsigned short getDisplaySize()
    {
        return this->diplaySize;
    }

    AccStatList(int ds) : diplaySize(ds) {}
    AccStatList() : diplaySize(0) {}
};