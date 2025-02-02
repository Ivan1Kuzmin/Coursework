#ifndef TRANSPORT
#define TRANSPORT

#include <string>
#include <iostream>
#include "Engine.h"
#include "Transmission.h"
#include "Model.h"
#include "Body.h"


class Transport
{
protected:
	Engine engine; // Двигатель
	Transmission transmission; // Коробка передач
	Body body; // Кузов
	Model model; // Модель
	int maxSpeed; // Максимальная скорость
	int passengersNumber; // Пассажировместимость
	float fuelLevel; // Объем бака

public:
	Transport() {};
	Transport(Model model, Engine engine, Transmission transmission, Body body, int speed, int passengers, int fuel);

	virtual ~Transport() = default;


	// Вывод траанспорта в консоль
	void Print();

	/////////////////////////

	// Получение максимальной скорости
	int GetMaxSpeed();
	// Получение пассажировместимости
	int GetPassengers();
	// Получение объема бака
	float GetFuel();

	// Получение двигателя
	Engine GetEngine();
	// Получение коробки передач
	Transmission GetTransmission();
	// Получение модели
	Model GetModel();
	// Получение кузова
	Body GetBody();

	/////////////////////////

	// Присвоение новой максимальной скорости
	void SetMaxSpeed(int speed);
	// Присвоение новой пассажировместимости
	void SetPassengers(int passengers);
	// Присвоение нового объема бака
	void SetFuel(float fuel);

	// Присвоение двигателя
	void SetEngine(Engine other);
	// Присвоение новой коробки передач
	void  SetTransmission(Transmission other);
	// Присвоение новой модели
	void  SetModel(Model other);
	// Присвоение новой кузова
	void  SetBody(Body other);



	Transport& operator=(const Transport& other);

	virtual void Move() {};
	virtual string WhatTransport();

};

#endif 