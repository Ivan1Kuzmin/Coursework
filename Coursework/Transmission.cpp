#include "Transmission.h"

Transmission::Transmission(int typeId, int gears)
{
    this->id = ++Transmission::count;
    this->typeId = typeId;
    this->gears = gears;
}

Transmission Transmission::InputTransmission()
{
    int typeId;
    int gears;

    do
    {
        cout << "Тип коробки (1-механическая, 2-автоматическая):\t";
        typeId = InputCorrectNumber();
    } while (typeId != 1 && typeId != 2);


    cout << "Количество передач:\t";
    gears = InputCorrectNumber();

    Transmission transmission(typeId, gears);
    return transmission;
}

void Transmission::PrintTransmission()
{
    cout << "Тип коробки:\t";
    if (this->typeId == 1)
    {
        cout << "механическая\n";
    }
    else
    {
        cout << "автоматическая\n";
    }
    cout << "Количество передач:\t" << this->gears << "\n";
}

int Transmission::GetTypeId()
{
    return this->typeId;
}