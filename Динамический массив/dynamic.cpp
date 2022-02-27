#include <iostream>
#include <locale>

using namespace std;

void createField(char** field, int rows, int columns);
void printField(char** field, int rows, int columns);
bool crossWins(char** field, int rows, int columns);

int main()
{
	setlocale(LC_ALL, "Russian");
	string stop = "\n----------------------------------------------------------------------------\n";
	int problem, flag = 1;
	char** field = NULL;
	int m = 0, n = 0;
	while (flag)
	{
		system("cls"); //Команда, очищающая консоль
		cout << "Практическая работа №2 ИКБО-03-21 Поведенок С.С. Варинат 22" << "\n\n" //Вывод меню
			"Задание 2\n"
			"Меню\n"
			"1) Заполнить поле.\n"
			"2) Вывести поле.\n"
			"3) Узнать, не победили ли крестики.\n"
			"4) Завершить проверку.\n";
		cout << "Ваш выбор: ";
		cin >> problem; //Ввод задания
		switch (problem) {
		case 1:
			cout << "Введите количество строк m: ";
			cin >> m;
			cout << "Введите количество столбцов n: ";
			cin >> n;
			while (n <= 0 || n > 1000 || m <= 0 || m > 1000)
			{
				cout << "Значения m и n не должны превышать 1000 и быть меньше 1. Попробуйте еще раз." << endl;
				cout << "Введите количество строк m: ";
				cin >> m;
				cout << "Введите количество столбцов n: ";
				cin >> n;
			}
			field = new char* [m];
			for (int i = 0; i < m; i++)
			{
				field[i] = new char[n];
			}
			createField(field, m, n);
			system("pause");
			break;
		case 2:
			if (m == 0 || n == 0)
			{
				cout << "Поле пусто." << endl;
			}
			else
			{
				cout << "На данный момент поле имеет следующий вид: " << endl;
				printField(field, m, n);
			}
			system("pause");
			break;
		case 3:
			if (m == 0 || n == 0)
			{
				cout << "Поле пусто." << endl;
			}
			else
			{
				if (crossWins(field, m, n))
				{
					cout << "Крестики победили!" << endl;
				}
				else
				{
					cout << "Крестики проиграли :(" << endl;
				}
			}
			system("pause");
			break;
		case 4:
			cout << "Спасибо, до свидания!" << endl;
			flag = false;
			break;
		default:
			cout << "Извините, я не совсем вас понимаю. Попробуйте ещё раз." << endl;
			system("pause");
		}
	}
}

void createField(char** field, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> field[i][j];
		}
	}
}

void printField(char** field, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

bool crossWins(char** field, int rows, int columns)
{
	int mainDiagonal = 0, horizontal = 0, vertical = 0, backDiagonal = 0;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < columns; col++)
		{
			if (field[row][col] == 'x')
			{
				for (int p = 1; p < 5; p++)
				{
					if (row + p < rows && field[row + p][col] == 'x')
					{
						vertical++;
					}
					else
					{
						vertical = 0;
					}
					if (col + p < columns && field[row][col + p] == 'x')
					{
						horizontal++;
					}
					else
					{
						horizontal = 0;
					}
					if (row + p < rows && col + p < columns && field[row + p][col + p] == 'x')
					{
						mainDiagonal++;
					}
					else
					{
						mainDiagonal = 0;
					}
					if (row + p < rows && col - p >= 0 && field[row + p][col - p] == 'x')
					{
						backDiagonal++;
					}
					else
					{
						backDiagonal = 0;
					}
				}
				if (horizontal == 4 || vertical == 4 || mainDiagonal == 4 || backDiagonal == 4)
				{
					return true;
				}
			}
			horizontal = 0;
			vertical = 0;
			mainDiagonal = 0;
			backDiagonal = 0;
		}
	}
	return false;
}
