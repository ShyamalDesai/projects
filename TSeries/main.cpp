#include <iostream>
#include "TimeSeries.h"
using namespace std;

int main()
{

    TimeSeries<double> tseries;
    tseries.addValue(9001, 1 );
    tseries.addValue(9005, 2 );
    tseries.addValue(9008, 3 );
    tseries.addValue(9009, 9 );

    TimeSeries<double> * result = tseries.sample(1, 0);
    std::cout << *result;

    delete result;
    return 0;
}
