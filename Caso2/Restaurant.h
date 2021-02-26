#ifndef RESTAURANTE_H
#define RESTAURANT_H

#include "Bicycle.h"
#include "Car.h"
#include "Motorcycle.h"


class Restaurant;

class Restaurant
{
    Vehicle * firstVehicle, * lastVehicle;
    public:
        Restaurant();
        void addVehicle(Vehicle *);
        void makeDelivery(string);
};

#endif