#include <iostream>
#include <vector>

using namespace std;

void create2Dvector(vector<vector<double>>& vec, int rows, int cols);
void print2Dvector(vector<vector<double>> vec, int rows, int cols);
void gauss(vector<vector<double>> vec, int rows, int cols);

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
			cout << "Введите количество коэффициентов n в дополненной матрице: ";
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
		case 3:
			gauss(vec, m, n);
			system("pause");
			break;
		case 4:
			flag = 0;
			cout << "Спасибо, до свидания!" << endl;
			break;
		default:
			cout << "Извините, я не совсем вас понимаю. Попробуйте ещё раз." << endl;
			system("pause");
		}
	}
}

void create2Dvector(vector<vector<double>>& vec, int rows, int cols)
{
	vec.resize(rows);
	for (int row = 0; row < rows; row++)
	{
		vec[row].resize(cols);
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
			if (col == cols - 2)
			{
				cout << "| ";
			}
		}
		cout << '\n';
	}
}

void gauss(vector<vector<double>> vec, int rows, int cols)
{
	bool flag = 0;
	double tmp;
	vector <double> solutions;
	solutions.resize(cols - 1);
	if (rows < cols - 1)
	{
		cout << "Система несовместна или имеет бесконечное количество решений." << endl;
	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			tmp = vec[i][i];
			for (int j = rows; j >= i; j--)
			{
				vec[i][j] /= tmp;
			}
			for (int j = i + 1; j < rows; j++)
			{
				tmp = vec[j][i];
				for (int k = rows; k >= i; k--)
				{
					vec[j][k] -= tmp * vec[i][k];
				}
			}
		}

		solutions[rows - 1] = vec[rows - 1][rows];
		for (int i = rows - 2; i >= 0; i--)
		{
			solutions[i] = vec[i][rows];
			for (int j = i + 1; j < rows; j++)
			{
				solutions[i] -= vec[i][j] * solutions[j];
			}
		}

		if (!flag)
		{
			for (int i = 0; i < rows; i++)
			{
				cout << solutions[i] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < rows; i++)
		{
			tmp = vec[i][i];
			for (int j = rows; j >= i; j--)
			{
				vec[i][j] /= tmp;
			}
			for (int j = i + 1; j < rows; j++)
			{
				tmp = vec[j][i];
				for (int k = rows; k >= i; k--)
				{
					vec[j][k] -= tmp * vec[i][k];
				}
			}
		}

		solutions[rows - 1] = vec[rows - 1][rows];
		for (int i = rows - 2; i >= 0; i--)
		{
			solutions[i] = vec[i][rows];
			for (int j = i + 1; j < rows; j++)
			{
				solutions[i] -= vec[i][j] * solutions[j];
			}
		}

		if (!flag)
		{
			for (int i = 0; i < rows; i++)
			{
				cout << solutions[i] << " ";
			}
			cout << endl;
		}
	}
}
