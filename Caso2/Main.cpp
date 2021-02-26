/*
 * Instituto Tecnológico de Costa Rica
 * Primer semestre, 2021
 * Análisis de algoritmos
 * Caso 2: Parte 2
 * 
 * Autores:
 *         -Diego Carrillo
 *         -Cristhian Esquivel
 *         -Sebastián López
 * 
 * Fecha de entrega: Martes 2 de marzo, 2021
 */

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


class Bicycle : public Vehicle
{
    public:
        Bicycle(){}
        Bicycle(double, double);
        double getTimeToArrive();
        void makeDelivery(string);
};

Bicycle::Bicycle(double pSpeed = 40, double pDistance = 0)
{
    speed = pSpeed;
    distanceToRestaurant = pDistance;
}

double Bicycle::getTimeToArrive()
{
    double timeToArrive = distanceToRestaurant / speed;
    return timeToArrive;
}

void Bicycle::makeDelivery(string pDelivery)
{
    cout << "The bicycle makes the delivery: " << pDelivery << "." << endl;
}


class Motorcycle : public Vehicle
{
    public:
        Motorcycle();
        Motorcycle(double, double);
        double getTimeToArrive();
        void makeDelivery(string);
};

Motorcycle::Motorcycle()
{
    speed = 100;
    distanceToRestaurant = 0;
}

Motorcycle::Motorcycle(double pSpeed, double pDistance)
{
    speed = pSpeed;
    distanceToRestaurant = pDistance;
}

double Motorcycle::getTimeToArrive()
{
    //It is added 1/6h for the wait time for the traffic
    double timeToArrive = distanceToRestaurant / speed + 1/6;
    return timeToArrive;
}

void Motorcycle::makeDelivery(string pDelivery)
{
    cout << "The motorcycle makes the delivery: " << pDelivery << "." << endl;
}

class Car : public Vehicle
{
    public:
        Car();
        Car(double, double);
        double getTimeToArrive();
        void makeDelivery(string);
};

Car::Car()
{
    speed = 80;
    distanceToRestaurant = 0;
}

Car::Car(double pSpeed, double pDistance)
{
    speed = pSpeed;
    distanceToRestaurant = pDistance;
}

double Car::getTimeToArrive()
{
    //It is added 1/4h for the wait time for the traffic
    double timeToArrive = distanceToRestaurant / speed + 1/4;
    return timeToArrive;
}

void Car::makeDelivery(string pDelivery)
{
    cout << "The car makes the delivery: " << pDelivery << "." << endl;
}


class Restaurant
{
    Vehicle * firstVehicle, * lastVehicle;
    public:
        Restaurant();
        void addVehicle(Vehicle *);
        void makeDelivery(string);
};

Restaurant::Restaurant()
{
    firstVehicle = lastVehicle = NULL;
}

void Restaurant::addVehicle(Vehicle * pVehicle)
{
    if (firstVehicle == NULL)
    {
        firstVehicle = lastVehicle = pVehicle;
    }

    else
    {
        lastVehicle->setNext(pVehicle);
        lastVehicle = pVehicle;
    }
}

void Restaurant::makeDelivery(string pDelivery)
{
    cout << "A new delivery comes." << endl;
    Vehicle * aux = firstVehicle;
    Vehicle * closestVehicle = aux;

    while (aux != NULL)
    {
        if (closestVehicle->getTimeToArrive() > aux->getTimeToArrive())
        {
            closestVehicle = aux;
        }

        aux = aux->getNext();
    }

    if (closestVehicle != NULL)
    {
        closestVehicle->makeDelivery(pDelivery);
    }
}

int main()
{
    Restaurant  * restaurant = new Restaurant;
    Vehicle * bike = new Bicycle(10,20);
    Vehicle * motorcycle = new Motorcycle(100, 20);
    Vehicle * car = new Car(70, 15);

    restaurant->addVehicle(bike);
    restaurant->addVehicle(motorcycle);
    restaurant->addVehicle(car);

    restaurant->makeDelivery("Burrito to the street 5");


    cout << "SE FINALIZO CON EXITO" << endl;

    return 0;
}