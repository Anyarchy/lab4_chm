#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>

using namespace std;

double A[4][4] = {
{ 6.7, 1.26, 0.81, 1.18 },
{ 1.26, 3.72, 1.30, 0.16 },
{ 0.81, 1.30, 5.88, 2.10 },
{ 1.18, 0.16, 2.10, 5.66 },
};

int main()
{
	SetConsoleCP(1251);// ��� ����� ���� ������� ��� ���
	SetConsoleOutputCP(1251); // �������� ��� ���

	cout << "__________________________________________________________________________________" << endl;
	cout << "������ �������:" << endl;
	for (int k = 0; k < 4; k++)
	{
		for (int z = 0; z < 4; z++)
		{
			cout << setw(5) << " " << A[k][z] << " " << " ";

		}
		cout << endl;
	}
	cout << endl;



	double M1[4][4];

	for (int i = 0; i <= 2; i++)
	{

		double  S1[4][4] = { { 1,	0,	0,	0 },{ 0,	1,	0,	0 },{ 0,	0,	1,	0 },{ 0,	0,	0,	1 } };
		double  S2[4][4] = { { 1,	0,	0,	0 },{ 0,	1,	0,	0 },{ 0,	0,	1,	0 },{ 0,	0,	0,	1 } };


		for (int j = 0; j < 4; j++)
		{

			if (j != 2 - i) {
				S1[2 - i][j] = -(A[2 - i + 1][j]) / A[2 - i + 1][2 - i];
			}
			else
			{
				S1[2 - i][j] = 1 / A[2 - i + 1][2 - i];
			}
			S2[2 - i][j] = A[3 - i][j];

		}

		cout << "__________________________________________________________________________________" << endl;
		cout << "������� �1 �� �������� �" << i << endl;
		for (int k = 0; k < 4; k++)
		{
			for (int z = 0; z < 4; z++)
			{
				cout << setw(5) << " " << S1[k][z] << " " << " ";

			}
			cout << endl;
		}
		cout << endl;
		cout << "__________________________________________________________________________________" << endl;
		cout << "������� �1^-1 �� �������� �" << i << endl;
		for (int k = 0; k < 4; k++)
		{
			for (int z = 0; z < 4; z++)
			{
				cout << setw(5) << " " << S2[k][z] << " " << " ";

			}
			cout << endl;
		}
		cout << endl;
		double  D1[4][4] = { { 0,	0,	0,	0 },{ 0,	0,	0,	0 },{ 0,	0,	0,	0 },{ 0,	0,	0,	0 } };
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int l = 0; l < 4; l++)
				{
					D1[i][j] += S2[i][l] * A[l][j];
				}

			}

		}


		double  D2[4][4] = { { 0,	0,	0,	0 },{ 0,	0,	0,	0 },{ 0,	0,	0,	0 },{ 0,	0,	0,	0 } };
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int l = 0; l < 4; l++)
				{
					D2[i][j] += D1[i][l] * S1[l][j];
				}

			}

		}




		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				A[i][j] = D2[i][j];

			}



		}

		cout << "__________________________________________________________________________________" << endl;
		cout << "������� � ���� �������� �" << i + 1 << endl;
		for (int k = 0; k < 4; k++)
		{
			for (int z = 0; z < 4; z++)
			{
				cout << setw(5) << " " << A[k][z] << " " << " ";

			}
			cout << endl;
		}
		cout << endl;


	}




	cout << endl;
	cout << "__________________________________________________________________________________" << endl;
	cout << "��������������� ������� ������i: " << "�^4-";




	int Lamv = 3;
	for (int i = 0; i < 4; i++)
	{

		if (i != 3) {
			cout << " (" << A[0][i] << ") " << "*�^" << Lamv << " - ";
		}
		else {
			cout << A[0][3] << ";" << endl;
		}

		Lamv--;
	}



	system("pause");
	return 0;

}
