#include <ctime>  
#include <iostream>  
#include <cstdlib>  
using namespace std;

void FillRand(int arr[], int n);
void Print(int arr[], int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	int m = 0;
	int l = 0;
	srand(time(NULL));
	n = rand() % 15;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	for (int i = 0; i < n; i++)
		(arr[i] % 2 == 0) ? m++ : l++;
	int* even = new int[m];
	int* odd = new int[l];
	
	
	int j = 0;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even[j] = arr[i];
			j++;
		}
		else
		{
			odd[k] = arr[i];
			k++;
		}
	}
	Print(even, m);
	Print(odd, l);
	
	delete[] arr;
	delete[] even;
	delete[] odd;
}

void FillRand(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}