#include "Vehicle.h"

class Bicycle;

class Bicycle : public Vehicle
{
    public:
        double getTimeToArrive();
        void makeDelivery(string);
};