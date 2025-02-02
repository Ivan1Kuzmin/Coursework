#include "Car.h"


Car Car::InputCar()
{
    Model model = Model::InputModel();
    Engine engine = Engine::InputEngine();
    Transmission transmission = Transmission::InputTransmission();
    Body body = Body::InputBody();


    int speed;
    cout << "Максимальная скорость:\t";
    cin >> speed;

    int passengers;
    cout << "Пассажировместимость:\t";
    cin >> passengers;

    float fuel;
    cout << "Объём бака:\t";
    cin >> fuel;


    Car car(model, engine, transmission, body, speed, passengers, fuel);
    return car;
}

string Car::WhatTransport()
{
    return "\nАвтомобиль.\n";
}

void Car::Move()
{
    cout << "\n****Машина едет****\n";
}