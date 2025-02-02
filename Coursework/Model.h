#pragma once
#include <iostream>
#include "CheckInput.h"
#include <string>
using namespace std;

// Модель
class Model
{
private:
    int id;
    string brand; // Марка (Например, KIA)
    string model;  // Модель
    string country;   // Страна производитель
public:
    static int count; // Каждый раз id  увеличивает на единицу
    Model() : id(0) {};
    Model(string brand, string modelName, string country);

    // Ввод с консоли
    static Model InputModel();
    // Вывод на консоль
    void PrintModel();


    // Получить марку
    string GetBrand();
    // Получить модель
    string GetModel();
    // Получить страну 
    string GetCountry();
};

