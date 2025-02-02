#include "Moto.h"

Moto Moto::InputMoto()
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


    Moto moto(model, engine, transmission, body, speed, passengers, fuel);
    return moto;
}

string Moto::WhatTransport()
{
    return "\nМотоцикл.\n";
}

void Moto::Move()
{
    cout << "\n****Мотоцикл едет****\n";
}