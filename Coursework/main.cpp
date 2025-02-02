#include "Car.h"
#include "Moto.h"
#include <locale.h>
#include <Windows.h>
#include <vector>
#include <memory>

// ����������� numeric_limits<streamsize>::max() � Windows.h
#ifdef max
#undef max
#endif


// ���������� �������
 
// ������� ��������� ��������� (������� ���������� ��� ������� ������ ��������� ��� ������)
void PrintTransports(vector<unique_ptr<Transport>>& transports)
{
	int i = 1;
	for (auto& transport : transports)
	{
		std::cout << "\n\n��������� ��� �������:\t" << i++ << "\n";
		transport->Print();
	}
}

// ������� �������� ��� ������
void PrintTransports(vector<unique_ptr<Transport>>& transports, string whatIs)
{
	Car car;
	Moto moto;

	if (whatIs == car.WhatTransport())
	{
		std::cout << "\n\n������ �����:\n";
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
		std::cout << "\n\n������ ����������:\n";
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
 
// ������� ������ ����� � ������������ ��������� (������ ���������, ��� �������)
void PrintTransportsByTransmission(vector<unique_ptr<Transport>>& transports, int type)
{
	Car car;

	if (type == 1)
	{
		cout << "\n������ � ������������ ��������:\n";
	}
	else
	{
		cout << "\n������ � �������������� ��������:\n";
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


// ��������� ������� ���������� (������ ��� ���������)
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

// ������� ����� ������ �������� ��� ����� ������ ������
void PrintPowerestTransport(vector<unique_ptr<Transport>>& transports, string whatIs)
{
	
	Car car;
	Moto moto;
	int needIndex;

	if (whatIs == car.WhatTransport())
	{
		needIndex = GetTransportIndex(transports, car.WhatTransport());
		cout << "\n\n����� ������ ������:\n";
	}
	else
	{
		needIndex = GetTransportIndex(transports, moto.WhatTransport());
		cout << "\n\n����� ������ ��������:\n";
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

// ������� ���������
void TransportDelete(vector<unique_ptr<Transport>>& transports, int index)
{
	if (index > transports.size())
	{
		cout << "\n� ������ ��� ������ ��� ����� �������.";
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

		std::cout << "\n�������:\n"
			<< "1 - �������� ������\n"										
			<< "2 - �������� ��������\n"									
			<< "3 - ������� ��������� ���������\n"							
			<< "4 - ������� ������ ����� � ������������ �������� �������\n" 
			<< "5 - ������� ��� ���������\n"								
			<< "6 - ������� ����� ������ ������\n"
			<< "7 - ������� ����� ������ ��������\n"
			<< "8 - ������� ���������\n"
			<< "9 - ����� �� ����\n";										
		cin >> chooseNumber;

		switch (chooseNumber)
		{
		case 1:		// "1 - �������� ������\n"
		{		
			Car car = Car::InputCar();
			transports.push_back(make_unique<Car>(car.GetModel(), car.GetEngine(), car.GetTransmission(), car.GetBody(), car.GetMaxSpeed(), car.GetPassengers(), car.GetFuel()));
			break;
		}

		case 2:		// "2 - �������� ��������\n"
		{
			Moto moto = Moto::InputMoto();
			transports.push_back(make_unique<Moto>(moto.GetModel(), moto.GetEngine(), moto.GetTransmission(), moto.GetBody(), moto.GetMaxSpeed(), moto.GetPassengers(), moto.GetFuel()));
			break;
		}

		case 3:		// "3 - ������� ��������� ���������\n"	
		{
			PrintTransports(transports);
			break;
		}
		case 4:		// "4 - ������� ������ ����� � ������������ �������� �������\n" 
		{
			int type;
			std::cout << "\n������� ��� ������� �������, ����� ������� ������ ����� � ���� ����� (1 - ����������, 2 - ���������): \t";
			do
			{
				cin >> type;

			} while (type != 1 && type != 2);

			PrintTransportsByTransmission(transports, type);
			
			break;
		}
		 
		case 5:		// "5 - ������� ��� ���������\n"
		{
			Moto moto;
			PrintTransports(transports, moto.WhatTransport());
			break;
		}
		
		case 6:		// "6 - ������� ����� ������ ������\n"
		{
			Car car;
			PrintPowerestTransport(transports, car.WhatTransport());
			break;
		}

		
		case 7:		// "7 - ������� ����� ������ ��������\n"
		{
			Moto moto;
			PrintPowerestTransport(transports, moto.WhatTransport());
			break;
		}

		case 8:		// "8 - ������� ���������\n"
		{
			int deleteNumber;
			cout << "\n\n����� ��������� �� ������ �� ������ �������. �������� ����� �� �������:\t";
			cin >> deleteNumber;
			TransportDelete(transports, deleteNumber - 1);
			break;
		}

		case 9: return false;

		default:  cout << "\n� ������ ��� ������ �����. ������� �����.\n";
		}

	}

	return 0;
}