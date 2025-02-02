#ifndef CAR
#define CAR

#include "Transport.h"

// Машина
class Car : public  Transport
{
    int id;
public:
    static int count; // Каждый раз id увеличивает на единицу
    Car() : id(0) {};
    Car(Model model, Engine engine, Transmission transmission, Body body, int speed, int passengers, int fuel)
        : Transport(model, engine, transmission, body, speed, passengers, fuel) {
        this->id = ++Car::count;
    };

    ~Car() override {};

    // Ввод с консоли
    static Car InputCar();
    static Car* InputCar(const char*);


    void Move() override;
    string WhatTransport() override;
};

#endif