#include<iostream>
using namespace std;
using std::cout;
using std::cin;
#define tab  "\t";

template<typename T> void Allocate(T**& arr, const int rows, const int cols);
template<typename T> void Clear(T**& arr, const int rows, const int cols = 0);
void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
template<typename T> void Print(T arr[], const int n);
template<typename T> void Print(T** arr, const int rows, const int cols);
template<typename T>T* PushBack(T arr[], int& n, const T value);
template<typename T>T* PushFront(T arr[], int& n, const T value);
template<typename T>T* pop_back(T arr[], int& n);
template<typename T>T* pop_front(T arr[], int& n);
template<typename T>T* Insert(T arr[], int& n, const T value, const int index);
template<typename T>T* Erase(T arr[], int& n, const int index);
template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** push_row_front(T** arr, int& rows, const int cols);
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int index);
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols);
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int index);
template<typename T> void push_col_back(T** arr, const int rows, int& cols);
template<typename T> void push_col_front(T** arr, const int rows, int& cols);
template<typename T> void insert_col(T** arr, const int rows, int& cols, int index);
template<typename T> void pop_col_back(T** arr, const int rows, int& cols);
template<typename T> void pop_col_front(T** arr, const int rows, int& cols);
template<typename T> void erase_col(T** arr, const int rows, int& cols, int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

#define DATATYPE double
//typedef int DataType;
typedef double DataType;

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1

	int n, index;
	DataType value;
	cout << "Введите размер массива: "; cin >> n;
	DataType* arr = new DataType[n];
	FillRand(arr, n);
	Print(arr, n);

	cout << "Введите добавляемое число: "; cin >> value;
	arr = PushBack(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое число: "; cin >> value;
	arr = PushFront(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите добавляемое число: "; cin >> value;
	cout << "Введите индекс добавляемого числа: "; cin >> index;
	arr = Insert(arr, n, value, index);
	Print(arr, n);
	//Print(arr = insert(arr, n value, index), n);

	cout << "Введите индекс удаляемого числа: "; cin >> index;
	arr = Erase(arr, n, index);
	Print(arr, n);

	delete[] arr;

#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows, cols, index;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество столбцов: "; cin >> cols;
	cout << "\tИСХОДНЫЙ МАССИВ" << endl;
	DataType** arr{nullptr};
	Allocate(arr, rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "\tВСТАВИТЬ СТРОКУ В КОНЦЕ МАССИВА" << endl;
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	cout << "\tВСТАВИТЬ СТРОКУ В НАЧАЛЕ МАССИВА" << endl;
	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);

	cout << "\tВСТАВИТЬ СТРОКУ ПО ИНДЕКСУ" << endl;
	cout << "Введите индекс вставляемой строки: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	FillRand(arr[index], cols, 100, 1000);
	Print(arr, rows, cols);

	cout << "\tУДАЛИТЬ СТРОКУ В КОНЦЕ МАССИВА" << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "\tУДАЛИТЬ СТРОКУ В НАЧАЛЕ МАССИВА" << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "\tУДАЛИТЬ СТРОКУ ПО ИНДЕКСУ" << endl;
	cout << "Введите индекс удаляемой строки: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "\tВСТАВИТЬ СТОЛБЕЦ В КОНЦЕ МАССИВА" << endl;
	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++) arr[i][cols - 1] = rand() % 1000;
	Print(arr, rows, cols);

	cout << "\tВСТАВИТЬ СТОЛБЕЦ В НАЧАЛЕ МАССИВА" << endl;
	push_col_front(arr, rows, cols);
	for (int i = 0; i < rows; i++) arr[i][0] = rand() % 1000;
	Print(arr, rows, cols);

	cout << "\tВСТАВИТЬ СТОЛБЕЦ ПО ИНДЕКСУ" << endl;
	cout << "Введите индекс вставляемого столбца: "; cin >> index;
	insert_col(arr, rows, cols, index);
	for (int i = 0; i < rows; i++) arr[i][index] = rand() % 1000;
	Print(arr, rows, cols);

	cout << "\tУДАЛИТЬ СТОЛБЕЦ В КОНЦЕ МАССИВА" << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "\tУДАЛИТЬ СТОЛБЕЦ В НАЧАЛЕ МАССИВА" << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "\tУДАЛИТЬ СТОЛБЕЦ ПО ИНДЕКСУ" << endl;
	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	Clear(arr, rows, cols);
#endif // DYNAMIC_MEMORY_2
}

template<typename T> void Allocate(T**& arr, const int rows, const int cols)
{
	arr = new T* [rows] {};

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols] {};
	}
}
template<typename T> void Clear(T**& arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)	delete[] arr[i];
	delete[] arr;
	// Зануляем указатель на массив
	arr = nullptr;
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)	*(arr + i) = rand() % (maxRand - minRand) + minRand;
}

void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++) 
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		arr[i] /= 100;
	}
}


void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)	arr[i][j] = rand() % (maxRand - minRand) + minRand;
	}
}

void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		minRand *= 100;
		maxRand *= 100;
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = double(rand() % (maxRand - minRand) + minRand) / 100;
		}
	}
}

template<typename T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	cout << endl;

}

template<typename T> void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

template<typename T>T* PushBack(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)	buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}

template<typename T>T* PushFront(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)	buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}

template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)	buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template<typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)	buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

template<typename T>T* Insert(T arr[], int& n, const T value, const int index)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i <= n; i++) i <= index ? buffer[i] = arr[i] : buffer[i] = arr[i - 1];
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}

template<typename T>T* Erase(T arr[], int& n, const int index)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)	i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)	buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new T[cols] {};
	rows++;
	return buffer;
}
template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)	buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new T[cols] {};
	rows++;
	return buffer;
}
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int index)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i <= rows; i++)	i <= index ? buffer[i] = arr[i] : buffer[i] = arr[i - 1];
	delete[] arr;
	buffer[index] = new T[cols] {};
	rows++;
	return buffer;
}

template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	delete[] arr[0];
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)	buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int index)
{
	delete[] arr[index];
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)	i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

template<typename T> void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T> void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T> void insert_col(T** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j <= cols; j++)	j <= index ? buffer[j] = arr[i][j] : buffer[j] = arr[i][j - 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T> void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j]; 
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T> void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T> void erase_col(T** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++) j < index ? buffer[j] = arr[i][j] : buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}