#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* PushBack(int arr[], int& n, const int value);
int* PushFront(int arr[], int& n, const int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* Insert(int arr[], int& n, const int value, const int index);
int* Delete(int arr[], int& n, const int index);



void main()
{
	setlocale(LC_ALL, "");
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
	arr = Delete(arr, n, index);
	Print(arr, n);

	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
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

int* PushBack(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
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
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}

int* Insert(int arr[], int& n, const int value, const int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		i < index ? buffer[i] = arr[i] :
		i == index ? buffer[index] = value :
		i > index ? buffer[i] = arr[i - 1] : 0;
	}
	delete[] arr;
	n++;
	return buffer;
}

int* Delete(int arr[], int& n, const int index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		i < index ? buffer[i] = arr[i] :
		i >= index ? buffer[i] = arr[i + 1] : 0;
	}
	delete[] arr;
	return buffer;
}