#include "Body.h"

Body::Body(string typeName, int doors, string color, string material)
{
    this->id = ++Body::count;
    this->doors = doors;
    this->type = typeName;
    this->color = color;
    this->material = material;
}

Body Body::InputBody()
{
    string type;
    int doors;
    string color;
    string material;

    cout << "Тип кузова:\t";
    type = CheckString(type);
    cout << "Количество дверей:\t";
    do
    {
        cin >> doors;
        if (doors < 0)
        {
            cout << "\nВведено некорректное число.\n";
        }
    } while (doors < 0);

    cout << "Цвет:\t";
    color = CheckString(color);

    cout << "Материал:\t";
    material = CheckString(material);

    Body body(type, doors, color, material);
    return body;
}

void Body::PrintBody()
{
    cout << "Тип кузова:\t" << this->type << "\n";
    cout << "Количество дверей:\t" << this->doors << "\n";
    cout << "Цвет:\t" << this->color << "\n";
    cout << "Материал кузова:\t" << this->material << "\n";
}