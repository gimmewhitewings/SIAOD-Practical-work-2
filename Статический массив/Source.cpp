#include <iostream>
#include <locale>

const int rowsNumber = 1000;
const int columnsNumber = 1000;

using namespace std;

void createField(char(*field)[columnsNumber], int rows, int columns);
void printField(char(*field)[columnsNumber], int rows, int columns);
bool crossWins(char(*field)[columnsNumber], int rows, int columns);

int main()
{
	setlocale(LC_ALL, "Russian");
	string stop = "\n----------------------------------------------------------------------------\n";
	int problem, flag = 1;
	char field[rowsNumber][columnsNumber] = { {"_"}};
	int m = 0, n = 0;
	while (flag)
	{
		system("cls"); //�������, ��������� �������
		cout << "������������ ������ �2 ����-03-21 ��������� �.�. ������� 22" << "\n\n" //����� ����
			"������� 2\n"
			"����\n"
			"1) ��������� ����.\n"
			"2) ������� ����.\n"
			"3) ������, �� �������� �� ��������.\n";
		cout << "��� �����: ";
		cin >> problem; //���� �������
		switch (problem) {
		case 1:
			cout << "������� ���������� ����� m: ";
			cin >> m;
			cout << "������� ���������� �������� n: ";
			cin >> n;
			while (n <= 0 || n > 1000 || m <= 0 || m > 1000)
			{
				cout << "�������� m � n �� ������ ��������� 1000 � ���� ������ 1. ���������� ��� ���." << endl;
				cout << "������� ���������� ����� m: ";
				cin >> m;
				cout << "������� ���������� �������� n: ";
				cin >> n;
			}
			createField(field, m, n);
			system("pause");
			break;
		case 2:
			if (m == 0 || n == 0)
			{
				cout << "���� �����." << endl;
			}
			else
			{
				cout << "�� ������ ������ ���� ����� ��������� ���: " << endl;
				printField(field, m, n);
			}
			system("pause");
			break;
		case 3:
			if (m == 0 || n == 0)
			{
				cout << "���� �����." << endl;
			}
			else
			{
				if (crossWins(field, m, n))
				{
					cout << "�������� ��������!" << endl;
				}
				else
				{
					cout << "�������� ��������� :(" << endl;
				}
			}
			cout << crossWins(field, m, n) << endl;
			system("pause");
			break;
		case 4:
			cout << "�������, �� ��������!";
			flag = false;
			break;
		default:
			cout << "��������, � �� ������ ��� �������.";
			system("pause");
		}
	}
}

void createField(char(*field)[columnsNumber], int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> field[i][j];
		}
	}
}

void printField(char(*field)[columnsNumber], int rows, int columns)
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

bool crossWins(char(*field)[columnsNumber], int rows, int columns)
{
	int mainDiagonal = 0, horizontal = 0, vertical = 0, backDiagonal = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (field[i][j] == 'x')
			{
				for (int p = 1; p < 6; p++)
				{
					if (field[i + p][j] == 'x')
					{
						horizontal++;
					}
					else if(field[i][j + p] == 'x')
					{
						vertical++;
					}
					else if (field[i + p][j + p] == 'x')
					{
						mainDiagonal++;
					}
					else if (field[i + p][j - p] == 'x')
					{
						backDiagonal++;
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