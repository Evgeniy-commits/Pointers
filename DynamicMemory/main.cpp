#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void PushBack(int arr[], int n);
void PushFront(int arr[], int n);
void Insert(int arr[], int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n]; 
	FillRand(arr, n);
	Print(arr, n);
	PushBack(arr, n);
	PushFront(arr, n);
	Insert(arr, n);
	

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

void PushBack(int arr[], int n)
{
	n++;
	int* arr1 = new int[n];
	int value;
	cout << "¬ведите добавл€емое число: "; cin >> value;
	for (int i = 0; i < n - 1; i++)
	{
		arr1[i] = arr[i];
	}
	arr1[n - 1] = value;
	Print(arr1, n);
	delete[] arr1;
}
void PushFront(int arr[], int n)
{
	n++;
	int* arr2 = new int[n];
	int value;
	cout << "¬ведите добавл€емое число: "; cin >> value;
	arr2[0] = value;
	for (int i = 0; i < n - 1; i++)
	{
		arr2[i + 1] = arr[i];
	}
	Print(arr2, n);
	delete[] arr2;
}
void Insert(int arr[], int n)
{
	n++;
	int* arr3 = new int[n];
	int value;
	int index;
	cout << "¬ведите добавл€емое число: "; cin >> value;
	cout << "¬ведите индекс элемента: "; cin >> index;
	
	for (int i = 0; i < n; i++)
	{
		i < index ? arr3[i] = arr[i] :
		i == index ? arr3[index] = value :
		i > index ? arr3[i] = arr[i - 1] : 0;
	}
	Print(arr3, n);
	delete[] arr3;
}