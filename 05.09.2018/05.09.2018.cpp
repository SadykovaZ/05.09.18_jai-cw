// 05.09.2018.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>

using namespace std;

int* fore_array(int **p, int n, int m, int &new_size)
{
	new_size = n * m;
	int index = 0;
	int* tmp = new int[new_size];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[index++] = p[i][j];
		}
	}
	return tmp;
}

void add_row(int **&p, int &n, int m)
{
	int **t = new int*[n + 1];
	for (int i = 0; i < n; i++)
	{
		t[i] = p[i];
	}
	delete[]p;

	p = t;
	p[n] = new int[m];
	n++;
}

void add_row1(int **&p, int &n, int m)
{
	int **t = new int*[n+1];
	
	for (int i = 0; i < n; i++)
	{
		t[i+1] = p[i];
	}
	delete[]p;

	p = t;
	p[0] = new int[m];
	n++;
}

void delete_last_row(int **&p, int &n, int m)
{
	delete[]p[n - 1];
	n--;
}
void delete_row1(int **&p, int &n, int m, int k)
{
	int **t = new int*[n + 1];

	for (int i = 0; i < k; i++)
	{
		t[i] = p[i];
	}
	for (int i = k+1; i < n; i++)
	{
		t[i + 1] = p[i];
	}
	delete[]p[n - 1];
	n--;
}

void add_row_k(int **&p, int &n, int m, int k)
{
	int **t = new int*[n + 1];

	for (int i = 0; i < k; i++)
	{
		t[i] = p[i];
	}
	for (int i = k; i < n; i++)
	{
		t[i+1] = p[i];
	}
	//t[k] = new int[m];

	delete[]p;

	p = t;
	p[k] = new int[m];
	n++;
}
void delete_row_k1(int **&p, int &n, int m, int k)
{
	delete[] p[k];
	for (int i = k; i < n; i++)
	{
		p[i] = p[i + 1];
	}
	n--;
}
int main()
{
	srand(time(NULL));
	int **p/*, *arr*/;
	int n=4, m=5/*, arr_size*/;
	/*cin >> n >> m;*/
	p = new int*[n];

	for (int i = 0; i < n; i++)
	{
		p[i] = new int[m];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] = rand() % 20 + 1;
			/*cout <<setw(3)<< p[i][j];*/
		}
		cout << endl;
	}
	cout << endl;
	/*p[0][0] = 100;
	add_row(p, n, m);
	p[4][0] = 200;
	p[4][1] = 200;*/

	
	/*add_row1(p, n, m);
	p[0][0] = 10;
	p[0][1] = 10;
	p[0][2] = 10;
	p[0][3] = 10;
	p[0][4] = 10;*/

	//add_row_k(p, n, m, 2);
	
	delete_row_k1(p, n, m,2);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{			
			cout << setw(5) << p[i][j];
		}
		cout << endl;
	}
	cout << endl;
	/*arr = fore_array(p, n, m, arr_size);

	for (int i = 0; i < arr_size; i++)
	{
		cout << setw(3)<<arr[i];
	}
	cout << endl;
	delete[]arr;*/

	for (int i = 0; i < n; i++)
	{
		delete[] p[i];
	}
	delete[]p;


	




	system("pause");
	return 0;
}

