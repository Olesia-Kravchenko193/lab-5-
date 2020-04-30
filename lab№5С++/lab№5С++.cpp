#include <iostream>
#include <string>
#include <fstream> //Библиотека для работы с файлами

using namespace std;

void Task1()
{
	ifstream fin("input.txt");//Создаём объект fin, который отвечает за считывание информации с файла(ввод инфы)
	ofstream fout("output.txt");//Записываем в файл(вывод инфы)
	string name[15], capital[15], lang[15], money[15], pol_sys[15], president[15];
	int area[15], population[15];
	int i = 0;
	do {
		fin >> name[i];//Записываем из нашего файла значения в переменные
		fin >> capital[i];
		fin >> lang[i];
		fin >> population[i];
		fin >> area[i];
		fin >> money[i];
		fin >> pol_sys[i];
		fin >> president[i];

		if (population[i] > 20000000)//Проверяем население
		{
			cout << name[i] << endl;
			cout << capital[i] << endl;
			cout << lang[i] << endl;
			cout << population[i] << endl;
			cout << area[i] << endl;
			cout << money[i] << endl;
			cout << pol_sys[i] << endl;
			cout << president[i] << endl << endl;
			//Запись результата в файл
			fout << name[i] << endl;
			fout << capital[i] << endl;
			fout << lang[i] << endl;
			fout << population[i] << endl;
			fout << area[i] << endl;
			fout << money[i] << endl;
			fout << pol_sys[i] << endl;
			fout << president[i] << endl << endl;
		}

		i++;
	} while (!fin.eof());//Дословно наше условие звучит как (Пока не конец файла)

	fin.close();//Закрываем файл 

}
/////////////////////////////////////////
////////////////////////////////////////

void Task2()
{
	ifstream fin("input1.2.txt");
	ofstream fout("output.txt");
	int number, sum = 0;
	int i = 0;
	do {
		fin >> number;//Считываем числа
		sum += number;
		i++;
	} while (!fin.eof());
	cout << sum;
	fout << "Результат складывания: " << sum;
	fin.close();
	fout.close();

}
/////////////////////////////////////////////
////////////////////////////////////////////

const int k = 3, n = 2, m = 3, l = 3;

struct Matrix {
	int matrix1[m][n];
	int matrix2[m][l];
	int matrix3[m][l];
};

void Task3()
{
	setlocale(LC_ALL, "Rus");
	ifstream fin1("input1.3.txt");
	ifstream fin2("input2.3.txt");
	ofstream fout("output.txt");

	Matrix mat[k];


	for (int q = 0; q < k; q++)
	{
		//Считываем 1 матрицу
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fin1 >> mat[q].matrix1[i][j];
			}
		}
		//Считываем 2 матрицу
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < l; j++)
			{
				fin2 >> mat[q].matrix2[i][j];
			}
		}
		if (m == l) {//Перемножение матриц
			for (int i = 0; i < m; i++)
				for (int j = 0; j < l; j++) {
					mat[q].matrix3[i][j] = 0;
					for (int k = 0; k < n; k++)
						mat[q].matrix3[i][j] += mat[q].matrix1[i][k] * mat[q].matrix2[k][j];
				}
		}

	}
	//вывод в консоль и файл 
	cout << "Содержимое 1 файла" << "\n";
	fout << "Содержимое 1 файла" << "\n";
	for (int q = 0; q < k; q++)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << mat[q].matrix1[i][j] << "   ";
				fout << mat[q].matrix1[i][j] << "   ";
			}
			cout << endl;
			fout << endl;
		}
		cout << "\n\n";
		fout << "\n\n";
	}
	cout << "Содержимое 2 файла" << "\n";
	fout << "Содержимое 2 файла" << "\n";
	for (int q = 0; q < k; q++)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < l; j++)
			{
				cout << mat[q].matrix2[i][j] << "   ";
				fout << mat[q].matrix2[i][j] << "   ";
			}
			cout << endl;
			fout << endl;
		}
		cout << "\n\n";
		fout << "\n\n";
	}
	cout << "Результат:" << "\n";
	fout << "Результат:" << "\n";
	for (int q = 0; q < k; q++)
	{
		for (int i = 0; i < m; i++)
		{
			fout << endl;
			for (int j = 0; j < l; j++)
			{
				cout << mat[q].matrix3[i][j] << "   ";
				fout << mat[q].matrix3[i][j] << "   ";
			}
			cout << endl;
			fout << endl;
		}
		cout << "\n\n";
		fout << "\n\n";
	}
	fout << endl;
	fin1.close();
	fin2.close();
	fout.close();

}

int main()
{
	int numTask;
	cout << "Enter num of task: ";
	cin >> numTask;

	switch (numTask)
	{
	case 1:
		Task1();
		break;
	case 2:
		Task2();
		break;
	case 3:
		Task3();
		break;

	}
}
