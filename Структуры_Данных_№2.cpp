//#define Debug

#include <iostream>
#include <complex>
#include <time.h>
#include <vector>
#include <thread>
using namespace::std;
using namespace::chrono;

unsigned int size_ = 1000;
//unsigned int size_ = 100;


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
	cout << endl;
}

//Возврат рандомного значения типа double в указанном диапазоне
double randomNumber(int min, int max)
{
	return min + rand() % (1000 * (max - min)) / 1000.0;
}

//Оценка сложности алгоритма
int algorithmСomplexity(unsigned int n)
{
	return (int)(2 * pow(n, 3));
}

int performance(float t, unsigned int c)
{
	return (int)((c / t) * pow(10, -6));
}

//============================================================================================= Начало написания 3 алгоритмов умножения матриц

	vector<vector<complex<double>>>firstMethod(const vector<vector<complex<double>>>& A, const vector<vector<complex<double>>> &B)//Первый метод||по формуле из линейной алгебры
	{
		vector< vector <complex <double>> > Arr(size_, vector<complex<double>>(size_));

		

		for (unsigned int i = 0; i < size_; i++)
		{
			for (unsigned int j = 0; j < size_; j++)
			{
				Arr[i][j] = 0;
				for (unsigned int k = 0; k < size_; k++)
				{
					Arr[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		return Arr;
	}

void secondMethod(vector<vector<complex<double>>> arr1, vector<vector<complex<double>>> arr2)//Второй метод||результат работы функции cblas_zgemm из библиотеки BLAS
{

}

void thirdMethod(vector<vector<complex<double>>> arr1, vector<vector<complex<double>>> arr2)//Третий метод||оптимизированный алгоритм по выбору
{

}

//============================================================================================= Конец  написания 3 алгоритмов умножения матриц


int main()
{
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));


	cout << "Создаем двумерные массивы комплексных чисел! Ожидайте..." << endl;
	auto startTime = high_resolution_clock::now();//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Начальное время

	//Выделяем память под двумерные массивы
	vector< vector <complex <double>> > Array1(size_, vector<complex<double>>(size_));
	vector< vector <complex <double>> > Array2(size_, vector<complex<double>>(size_));

	//Инициализируем массивы комплексными числами
	for (unsigned int i = 0; i < size_; i++)
	{
		for (unsigned int j = 0; j < size_; j++)
		{
			Array1[i][j] = complex<double>(randomNumber(1,1000),randomNumber(1,1000));
			Array2[i][j] = complex<double>(randomNumber(1,1000),randomNumber(1,1000));
		}
	}
	
	auto endTime = high_resolution_clock::now();//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Конечное время
	duration<float> searchTime = endTime - startTime;
	unsigned int c = algorithmСomplexity(size_);
	system("cls");
	cout << "Время создания и заполнения двух массивов: " << searchTime.count() << "с" << endl;
	cout << "Сложность алгоритма = " << c << endl;
	cout << "Производительность алгоритма = " << performance(searchTime.count(), c) << " MFlops" << endl << endl;


#if defined(Debug)//Вывод
	PrintMatrix(Array1);
	PrintMatrix(Array2);
#endif // gebug
	
	//========================================  ПЕРВЫЙ МЕТОД ПРОИЗВЕДЕНИЯ  ===========================================

	cout << "Умножаем матрицы 1 способом: " << endl;

	auto startTime1 = high_resolution_clock::now();//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	vector< vector <complex <double>> > Arr1 = firstMethod(Array1, Array2);
	
	auto endTime1 = high_resolution_clock::now();//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	duration<float> Time1 = endTime1 - startTime1;

	unsigned int Complexity1 = algorithmСomplexity(size_);//Сложность 1 алгоритма
	cout << "Время произведения матриц первым методом: " << Time1.count() << "с" << endl;
	cout << "Производительность первого алгоритма произведения матриц = " << performance(Time1.count(), Complexity1) << " MFlops" << endl;

#if defined(Debug)//Вывод
	PrintMatrix(Arr1);
#endif // gebug

	//========================================  ВТОРОЙ МЕТОД ПРОИЗВЕДЕНИЯ  ===========================================


}


