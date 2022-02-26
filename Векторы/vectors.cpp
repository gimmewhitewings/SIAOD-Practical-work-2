#include <iostream>
#include <vector>

using namespace std;

void create2Dvector(vector<vector<double>>& vec, int rows, int cols);
void print2Dvector(vector<vector<double>> vec, int rows, int cols);

int main()
{
	setlocale(LC_ALL, "Russian");
	string stop = "\n----------------------------------------------------------------------------\n";
	int problem, flag = 1;
	int m = 0, n = 0;
	vector <vector <double>> vec;
	while (flag)
	{
		system("cls");
		cout << "Практическая работа №2 ИКБО-03-21 Поведенок С.С. Варинат 22" << "\n\n" //Вывод меню
			"Задание 3\n"
			"Меню\n"
			"1) Заполнить систему.\n"
			"2) Вывести систему.\n"
			"3) Найти решение.\n"
			"4) Завершить проверку.\n";
		cout << "Ваш выбор: ";
		cin >> problem; //Ввод задания
		switch (problem) {
		case 1:
			cout << "Введите количество уравнений m: ";
			cin >> m;
			cout << "Введите количество переменных n: ";
			cin >> n;
			while (n <= 0 || m <= 0)
			{
				cout << "Значения m и n не должны быть меньше 1. Попробуйте еще раз." << endl;
				cout << "Введите количество строк m: ";
				cin >> m;
				cout << "Введите количество столбцов n: ";
				cin >> n;
			}
			create2Dvector(vec, m, n);
			system("pause");
			break;
		case 2:
			if (m == 0 || n == 0)
			{
				cout << "Система пока не введена." << endl;
			}
			else
			{
				cout << "Вывод системы:" << endl;
				print2Dvector(vec, m, n);
			}
			system("pause");
			break;
		}
	}
}

void create2Dvector(vector<vector<double>>& vec, int rows, int cols)
{
	vec.resize(rows);
	for (int row = 0; row < rows; row++)
	{
		vec[row].resize(cols);
		cout << "Введите " << cols << " коэффициентов для заполнения строки " << row + 1 << endl;
		for (int col = 0; col < cols; col++)
		{
			cin >> vec[row][col];
		}
	}
}

void print2Dvector(vector<vector<double>> vec, int rows, int cols)
{
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			cout << vec[row][col] << " ";
			if (col == cols - 1)
			{
				cout << "| ";
			}
		}
		cout << '\n';
	}
}
