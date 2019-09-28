#include <iostream>
#include "func_for_j_g.h"

using namespace std;

int main()
{
	float** a; unsigned n, m, i, j; float b[10];
	setlocale(LC_ALL, "Rus");

	cout << "Введите количество строк матрицы: ";
	cin >> n;
	cout << "Введите количество столбцов матрицы: ";
	cin >> m;
	a = create_matrix(n, m);

	//заполнение столбца свободных членов
	for (i = 0; i < n; i++) {
		cout << "b[" << i << "] = ";
		cin >> b[i];
	}

	print_matrix(n, m, a);

	for (i = 0; i < n; i++)
		cout << b[i] << "\n";
	

	for (i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}
