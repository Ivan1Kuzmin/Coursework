#include "CheckInput.h"
#include <iostream>
using namespace std;

// Обработка исключений на ввод положительного числа
int InputCorrectNumber()
{
	// Наше число
	int number;

	while (true)
	{
		try
		{
			cin >> number;

			// Проверяем, ввёл ли пользователь вместо числа символ
			// если ввод не является числом, то cin.fail() возвращает true. 
			// В этом случае мы игнорируем ввод
			if (cin.fail())
			{
				// Сбрасываем состояние потока 
				cin.clear();
				// Мгнорируем неверный ввод
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				throw invalid_argument("Введено не целое число. Попробуйте снова.");
			}

			// Проверяем, что число положительное
			if (number <= 0)
			{
				throw invalid_argument("Число должно быть положительным. Попробуйте снова.\n");
			}

			// Если все в порядке, выходим из цикла
			break;
		}
		catch (const invalid_argument& e)
		{
			cerr << "Ошибка: " << e.what() << endl;
		}
	}
	return number;
}

string CheckString(string String)
{
	if (char(cin.peek()) == '\n')
	{
		cin.ignore();
	}
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	getline(cin, String);
	return String;
}