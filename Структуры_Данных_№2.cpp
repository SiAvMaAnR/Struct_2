#include <iostream>
#include <complex>
#include <time.h>
using namespace::std;


//unsigned int size_ = 4096;
unsigned int size_ = 5;


//Вывод матрицы
void PrintMatrix(complex<double>** arr)
{
	for (unsigned int i = 0; i < size_; i++)
	{
		for (unsigned int j = 0; j < size_; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

//Возврат рандомного значения типа double в указанном диапазоне
double randomNumber(int min, int max)
{
	return min + rand() % (1000 * (max - min)) / 1000.0;
}
//============================================================================================= Начало написания 3 алгоритмов умножения матриц




















//============================================================================================= Конец  написания 3 алгоритмов умножения матриц


int main()
{
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));

	//Выделяем память под двумерные массивы
	complex<double>** Array1 = new complex<double> * [size_];
	complex<double>** Array2 = new complex<double> * [size_];
	for (unsigned int i = 0; i < size_; i++) 
	{
		Array1[i] = new complex<double>[size_];
		Array2[i] = new complex<double>[size_];
	}

	//Инициализируем массивы комплексными числами
	for (unsigned int i = 0; i < size_; i++)
	{
		for (unsigned int j = 0; j < size_; j++)
		{
			Array1[i][j] = complex<double>(randomNumber(1,1000),randomNumber(1,1000));
		}
	}

	//Вывод
	PrintMatrix(Array1);





	delete[] Array1;
	delete[] Array2;
}


