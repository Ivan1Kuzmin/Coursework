#pragma once
#include <string.h>
#include "CheckInput.h"
using namespace std;

// Коробка передач
class Transmission
{
private:
    int id;
    int typeId; // Тип коробки ("механическая", "автоматическая")
    int gears; // Количество передач
public:
    static int count; // Каждый раз id увеличивает на единицу
    Transmission() : id(0) {};
    Transmission(int typeId, int gears);

    // Ввод с консоли
    static Transmission InputTransmission();
    // Вывод на консоль
    void PrintTransmission();

    // Получить тип коробки
    int GetTypeId();
};
