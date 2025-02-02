#include "Model.h"

Model::Model(string brand, string modelName, string country)
{
    this->id = ++Model::count;
    this->brand = brand;
    this->model = modelName;
    this->country = country;
}

Model Model::InputModel()
{
    string brand;
    string modelName;
    string country;

    cout << "Марка:\t";
    brand = CheckString(brand);
    cout << "Модель:\t";
    modelName = CheckString(modelName);
    cout << "Страна производитель:\t";
    country = CheckString(country);

    Model model(brand, modelName, country);
    return model;
}

void Model::PrintModel()
{
    cout << "Марка:\t" << this->brand << "\n";
    cout << "Модель:\t" << this->model << "\n";
    cout << "Страна производитель:\t" << this->country << "\n";
}

string Model::GetBrand()
{
    return this->brand;
}

string Model::GetModel()
{
    return this->model;
}

string Model::GetCountry()
{
    return this->country;
}