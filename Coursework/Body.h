#pragma once
#include <string>
#include <iostream>
#include "CheckInput.h"
using namespace std;

// Кузов
class Body
{
private:
    int id;
    string type; // Тип кузова
    int doors; // Количество дверей
    string color; // Цвет
    string material; // Материал
public:
    static int count; // Каждый раз id увеличивает на единицу
    Body() : id(0) {};
    Body(string typeName, int doors, string color, string material);

    // Ввод с консоли
    static Body InputBody();
    // Вывод на консоль
    void PrintBody();
};



