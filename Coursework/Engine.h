#pragma once
#include <string>
#include <iostream>
#include "CheckInput.h"
using namespace std;

// Двигатель
class Engine
{
private:
    int id;  // Идентификатор
    string model; // Название модели двигателя
    int typeId; // Тип двигателя (бензиновый или дизельный)
    int horsePowers; // Мощность в лошадиных силах
    int valueCylindres; // Количество цилиндров
public:
    static int count; // Каждый раз id увеличивает на единицу
    Engine() : id(0) {};
    Engine(string model, int typeId, int horsePowers, int valueCylindres);

    // Ввод с консоли
    static Engine InputEngine();
    // Вывод на консоль
    void PrintEngine();

    // Получение мощности
    int GetHorsePowers();
    // Задать тип двигателя
    void SetType(int id);

    // Увеличение мощности на единицу
    void operator + (int number);
};
