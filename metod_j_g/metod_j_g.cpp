#include <iostream>
#include "func_for_j_g.h"

using namespace std;

int main()
{
	float** a; unsigned n, m, i, j; float b[10];
	unsigned id_row, id_row_old = 0; unsigned k, lead;
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

	for (j = 0; j < n; j++) {
		for (i = 0; i < n; i++) {
			if (a[i][j] > 0)
			{
				id_row = i;
				unsigned flag = check_line(id_row, a, id_row_old);
				if (flag == 0) {
					lead = a[i][j];
					for (k = j; k < n; k++)
						a[i][k] /= lead;
					b[k] /= lead;
				}
			}
		}
	}

	for (i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}
