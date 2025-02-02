#include "Car.h"
#include "Moto.h"
#include <locale.h>
#include <Windows.h>
#include <vector>
#include <memory>

// Конфликтует numeric_limits<streamsize>::max() с Windows.h
#ifdef max
#undef max
#endif


// ПРИКЛАДНЫЕ ФУНКЦИИ
 
// Вывести имеющийся транспорт (сделать перегрузку для вывести только мотоциклы или машины)
void PrintTransports(vector<unique_ptr<Transport>>& transports)
{
	int i = 1;
	for (auto& transport : transports)
	{
		std::cout << "\n\nТранспорт под номером:\t" << i++ << "\n";
		transport->Print();
	}
}

// Вывести мотоцикл или машину
void PrintTransports(vector<unique_ptr<Transport>>& transports, string whatIs)
{
	Car car;
	Moto moto;

	if (whatIs == car.WhatTransport())
	{
		std::cout << "\n\nСписок машин:\n";
		for (auto& transport : transports)
		{
			if (transport->WhatTransport() == car.WhatTransport())
			{
				transport->Print();
				std::cout << "\n";
			}
		}
	}
	else
	{
		std::cout << "\n\nСписок мотоциклов:\n";
		for (auto& transport : transports)
		{
			if (transport->WhatTransport() == moto.WhatTransport())
			{
				transport->Print();
				std::cout << "\n";
			}
		}
	}
}
 
// вывести список машин с определенной передачей (список транспорт, опр коробку)
void PrintTransportsByTransmission(vector<unique_ptr<Transport>>& transports, int type)
{
	Car car;

	if (type == 1)
	{
		cout << "\nМашины с механической коробкой:\n";
	}
	else
	{
		cout << "\nМашины с автоматической коробкой:\n";
	}

	for (auto& transport : transports)
	{
		if (transport->WhatTransport() == car.WhatTransport())
		{


			if (transport->GetTransmission().GetTypeId() == type)
			{
				cout << transport->GetModel().GetBrand() << " " << transport->GetModel().GetModel() << "\n";
			}
		}
	}
}


// Получение нужного транспорта (машины или мотоцикла)
int GetTransportIndex(vector<unique_ptr<Transport>>& transports, string whatis)
{
	for (int i = 0 ; i < transports.size(); i++)
	{
		if (transports[i]->WhatTransport() == whatis)
		{
			return i;
		}
	}
}

// Вывести самый мощный мотоцикл или самую мощную машину
void PrintPowerestTransport(vector<unique_ptr<Transport>>& transports, string whatIs)
{
	
	Car car;
	Moto moto;
	int needIndex;

	if (whatIs == car.WhatTransport())
	{
		needIndex = GetTransportIndex(transports, car.WhatTransport());
		cout << "\n\nСамая мощная машина:\n";
	}
	else
	{
		needIndex = GetTransportIndex(transports, moto.WhatTransport());
		cout << "\n\nСамый мощный мотоцикл:\n";
	}

	unique_ptr<Transport> temp{make_unique<Transport>(transports[needIndex]->GetModel(),
													   transports[needIndex]->GetEngine(), 
													   transports[needIndex]->GetTransmission(), 
													   transports[needIndex]->GetBody(),
													   transports[needIndex]->GetMaxSpeed(),
													   transports[needIndex]->GetPassengers(),
													   transports[needIndex]->GetFuel()) };


	for (int i = 1; i < transports.size(); i++)
	{
		if (transports[i]->WhatTransport() == whatIs)
		{
			if (temp->GetEngine().GetHorsePowers() < transports[i]->GetEngine().GetHorsePowers())
			{
				temp->SetModel(transports[i]->GetModel());
				temp->SetEngine(transports[i]->GetEngine());
				temp->SetTransmission(transports[i]->GetTransmission());
				temp->SetBody(transports[i]->GetBody());
				temp->SetMaxSpeed(transports[i]->GetMaxSpeed());
				temp->SetPassengers(transports[i]->GetPassengers());
				temp->SetFuel(transports[i]->GetFuel());

			}
		}
	}
	temp->Print();
	
 }

// Удалить транспорт
void TransportDelete(vector<unique_ptr<Transport>>& transports, int index)
{
	if (index > transports.size())
	{
		cout << "\nВ списке нет машины под таким номером.";
	}
	else
	{
		transports.erase(transports.begin() + index);
	}
}




int Body::count = 0;
int Engine::count = 0;
int Transmission::count = 0;
int Model::count = 0;
int Car::count = 0;
int Moto::count = 0;

int main()
{
	 system("chcp 1251");
	 SetConsoleCP(1251);
	 SetConsoleOutputCP(1251);

	vector<unique_ptr<Transport>> transports;

	while (true)
	{
		unsigned int chooseNumber;

		std::cout << "\nВведите:\n"
			<< "1 - добавить машину\n"										
			<< "2 - добавить мотоцикл\n"									
			<< "3 - вывести имеющийся транспорт\n"							
			<< "4 - вывести список машин с определенной коробкой передач\n" 
			<< "5 - вывести все мотоциклы\n"								
			<< "6 - вывести самую мощную машину\n"
			<< "7 - вывести самый мощный мотоцикл\n"
			<< "8 - удалить транспорт\n"
			<< "9 - выйти из меню\n";										
		cin >> chooseNumber;

		switch (chooseNumber)
		{
		case 1:		// "1 - добавить машину\n"
		{		
			Car car = Car::InputCar();
			transports.push_back(make_unique<Car>(car.GetModel(), car.GetEngine(), car.GetTransmission(), car.GetBody(), car.GetMaxSpeed(), car.GetPassengers(), car.GetFuel()));
			break;
		}

		case 2:		// "2 - добавить мотоцикл\n"
		{
			Moto moto = Moto::InputMoto();
			transports.push_back(make_unique<Moto>(moto.GetModel(), moto.GetEngine(), moto.GetTransmission(), moto.GetBody(), moto.GetMaxSpeed(), moto.GetPassengers(), moto.GetFuel()));
			break;
		}

		case 3:		// "3 - вывести имеющийся транспорт\n"	
		{
			PrintTransports(transports);
			break;
		}
		case 4:		// "4 - вывести список машин с определенной коробкой передач\n" 
		{
			int type;
			std::cout << "\nВведите тип коробки передач, чтобы вывести список машин с этим типом (1 - бензиновый, 2 - дизельный): \t";
			do
			{
				cin >> type;

			} while (type != 1 && type != 2);

			PrintTransportsByTransmission(transports, type);
			
			break;
		}
		 
		case 5:		// "5 - вывести все мотоциклы\n"
		{
			Moto moto;
			PrintTransports(transports, moto.WhatTransport());
			break;
		}
		
		case 6:		// "6 - вывести самую мощную машину\n"
		{
			Car car;
			PrintPowerestTransport(transports, car.WhatTransport());
			break;
		}

		
		case 7:		// "7 - вывести самый мощный мотоцикл\n"
		{
			Moto moto;
			PrintPowerestTransport(transports, moto.WhatTransport());
			break;
		}

		case 8:		// "8 - удалить транспорт\n"
		{
			int deleteNumber;
			cout << "\n\nКакой транспорт по списку вы хотите удалить. Напишите номер по порядку:\t";
			cin >> deleteNumber;
			TransportDelete(transports, deleteNumber - 1);
			break;
		}

		case 9: return false;

		default:  cout << "\nВ списке нет такого числа. Введите снова.\n";
		}

	}

	return 0;
}