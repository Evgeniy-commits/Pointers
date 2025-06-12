#include<iostream>
using namespace std;
using std::cout;
using std::cin;
#define tab  "\t";

void Allocate(int**& arr, const int rows, const int cols);
void Clear(int** arr, const int rows);
void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int* PushBack(int arr[], int& n, const int value);
int* PushFront(int arr[], int& n, const int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* Insert(int arr[], int& n, const int value, const int index);
int* Erase(int arr[], int& n, const int index);
int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, int index);
int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, int index);
void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
void insert_col(int** arr, const int rows, int& cols, int index);
void pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
void erase_col(int** arr, const int rows, int& cols, int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2


void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1

	int n, value, index;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	/*cout << "Введите добавляемое число: "; cin >> value;
	arr = PushBack(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое число: "; cin >> value;
	arr = PushFront(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);*/

	cout << "Введите добавляемое число: "; cin >> value;
	cout << "Введите индекс добавляемого числа: "; cin >> index;
	arr = Insert(arr, n, value, index);
	Print(arr, n);

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
	int** arr{nullptr};
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

	Clear(arr, rows);
#endif // DYNAMIC_MEMORY_2
}

void Allocate(int**& arr, const int rows, const int cols)
{
	arr = new int* [rows] {};

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)	delete[] arr[i];
	delete[] arr;
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)	*(arr + i) = rand() % (maxRand - minRand) + minRand;
}

void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)	arr[i][j] = rand() % (maxRand - minRand) + minRand;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void Print(int** arr, const int rows, const int cols)
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

int* PushBack(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)	buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	arr[n] = value;
	n++;
	return arr;
}

int* PushFront(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)	buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)	buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)	buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

int* Insert(int arr[], int& n, const int value, const int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i <= n; i++) i <= index ? buffer[i] = arr[i] : buffer[i] = arr[i - 1];
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}

int* Erase(int arr[], int& n, const int index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)	i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)	buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)	buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** insert_row(int** arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i <= rows; i++)	i <= index ? buffer[i] = arr[i] : buffer[i] = arr[i - 1];
	delete[] arr;
	buffer[index] = new int[cols] {};
	rows++;
	return buffer;
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)	buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int** erase_row(int** arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)	i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_col(int** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j <= cols; j++)	j <= index ? buffer[j] = arr[i][j] : buffer[j] = arr[i][j - 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void pop_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j]; 
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void pop_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void erase_col(int** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++) j < index ? buffer[j] = arr[i][j] : buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}