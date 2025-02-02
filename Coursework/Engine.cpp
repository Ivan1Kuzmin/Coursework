#include "Engine.h"

Engine::Engine(string model, int typeId, int horsePowers, int valueCylindres)
{
    this->id = ++Engine::count;
    this->model = model;
    this->typeId = typeId;
    this->horsePowers = horsePowers;
    this->valueCylindres = valueCylindres;
}

Engine Engine::InputEngine()
{
    string model;
    int typeId;
    int horsePowers;
    int valueCylindres;

    cout << "Модель двигателя:\t";
    model = CheckString(model);
    do
    {
        cout << "Тип двигателя (Напишите цифру: 1-бензиновый, 2-дизельный):\t";
        typeId = InputCorrectNumber();
    } while (typeId != 1 && typeId != 2);

    cout << "Мощность:\t";
    horsePowers = InputCorrectNumber();
    cout << "Количество цилиндров:\t";
    valueCylindres = InputCorrectNumber();

    Engine engine(model, typeId, horsePowers, valueCylindres);
    return engine;
}

void Engine::PrintEngine()
{
    cout << "Модель двигателя:\t" << this->model << "\n";
    cout << "Тип двигателя:\t";
    if (this->typeId == 1)
    {
        cout << "бензиновый\n";
    }
    else
    {
        cout << "дизельный\n";
    }
    cout << "Мощность:\t" << this->horsePowers << "\n";
    cout << "Количетсво цилиндров:\t" << this->valueCylindres << "\n";
}

int Engine::GetHorsePowers()
{
    return this->horsePowers;
}

void Engine::SetType(int id)
{
    this->typeId = id;
}

void Engine::operator + (int number)
{
    this->horsePowers += number;
}