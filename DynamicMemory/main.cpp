#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n]; 
	FillRand(arr, n);
	Print(arr, n);
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

	int* arr2 = new int[n];
	cout << "¬ведите добавл€емое число: "; cin >> value;
	arr2[0] = value;
	for (int i = 0; i < n - 1; i++)
	{
		arr2[i + 1] = arr[i];
	}
	Print(arr2, n);

	delete[] arr;
	delete[] arr1;
	delete[] arr2;

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