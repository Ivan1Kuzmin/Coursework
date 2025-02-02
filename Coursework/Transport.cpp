#include "Transport.h"


Transport::Transport(Model model, Engine engine, Transmission transmission, Body body, int speed, int passengers, int fuel)
{
	this->model = model;
	this->engine = engine;
	this->transmission = transmission;
	this->body = body;
	this->maxSpeed = speed;
	this->passengersNumber = passengers;
	this->fuelLevel = fuel;
}

void Transport::Print()
{
	this->model.PrintModel();
	this->engine.PrintEngine();
	this->transmission.PrintTransmission();
	this->body.PrintBody();
	cout << "Максимальная скорость:\t" << this->GetMaxSpeed() << "\n";
	cout << "Пассажировместимость:\t" << this->GetPassengers() << "\n";
	cout << "Объем бака:\t" << this->GetFuel() << "\n";

}

///////////////////////////////////////////////

void Transport::SetEngine(Engine other)
{
	this->engine = other;
}

void  Transport::SetTransmission(Transmission other)
{
	this->transmission = other;
}

void  Transport::SetModel(Model other)
{
	this->model = other;
}

void  Transport::SetBody(Body other)
{
	this->body = other;
}


void Transport::SetMaxSpeed(int speed)
{
	this->maxSpeed = speed;
}

void Transport::SetPassengers(int passengers)
{
	this->passengersNumber = passengers;
}

void Transport::SetFuel(float fuel)
{
	this->fuelLevel = fuel;
}

///////////////////////////////////////////////

Engine Transport::GetEngine()
{
	return this->engine;
}

Model Transport::GetModel()
{
	return this->model;
}

Transmission Transport::GetTransmission()
{
	return this->transmission;
}

Body Transport::GetBody()
{
	return this->body;
}

int Transport::GetMaxSpeed()
{
	return this->maxSpeed;
}

int Transport::GetPassengers()
{
	return this->passengersNumber;
}

float Transport::GetFuel()
{
	return this->fuelLevel;
}

///////////////////////////////////////////////////////

string Transport::WhatTransport()
{
	return "\n++++ Транспорт перемещается ++++\n";
}

Transport& Transport::operator=(const Transport& other)
{
	if (this != &other)
	{
		this->fuelLevel = other.fuelLevel;
		this->passengersNumber = other.passengersNumber;
		this->maxSpeed = other.maxSpeed;
	}

	return *this;
}