#ifndef vehicle_h
#define vehicle_h


#include <iostream>

using namespace std;


class Vehicle
{
    protected:
        double speed;
        double distanceToRestaurant;
        Vehicle * next = NULL;

    public:
        virtual double getTimeToArrive() = 0;
        virtual void makeDelivery(string) = 0;
        void setNext(Vehicle * pVehicle){next = pVehicle;}
        Vehicle * getNext(){return next;}
};
#endif


