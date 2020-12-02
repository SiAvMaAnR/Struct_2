#include <iostream>
#include <complex>
#include <time.h>
#include <vector>
#include <thread>
using namespace::std;
using namespace::chrono;

//unsigned int size_ = 4096;
unsigned int size_ = 5;


//Вывод матрицы
void PrintMatrix(vector<vector<complex<double>>> arr)
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

void firstMethod()
{

}


















//============================================================================================= Конец  написания 3 алгоритмов умножения матриц


int main()
{
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));

	auto startTime = high_resolution_clock::now;//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Начальное время

	//Выделяем память под двумерные массивы
	vector< vector <complex <double>> > Array1(size_, vector<complex<double>>(size_));
	vector< vector <complex <double>> > Array2(size_, vector<complex<double>>(size_));

	//Инициализируем массивы комплексными числами
	for (unsigned int i = 0; i < size_; i++)
	{
		for (unsigned int j = 0; j < size_; j++)
		{
			Array1[i][j] = complex<double>(randomNumber(1,1000),randomNumber(1,1000));
		}
	}
	
	auto endTime = high_resolution_clock::now;//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Конечное время
	

	//Вывод
	PrintMatrix(Array1);
	cout << "Время создания и заполнения двух массивов: " << search_time << endl;
	firstMethod();

}


