#include <iostream>
#include <math.h>
#include "func_for_j_g.h"

using namespace std;

int main()
{
	float** a; unsigned n, m, i, j; float b[10]; float mass[10][10];
	unsigned id_row, id_row_old = 1; int k, g = 0; float lead;
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
	cout << endl;

	for (j = 0; j < n; j++) {
		for (i = g; i < n; i++) {
			if (a[i][j] != 0)
			{
				id_row = i;
				unsigned flag = check_line(id_row, a, id_row_old);
				if (flag == 0) {
					id_row_old = id_row;
					lead = a[i][j];
					for (k = j; k < n; k++)
						a[i][k] /= lead;
					b[i] /= lead;
					
					g = i;
					for (k = 0; k < n; k++)
					for (int w = 0; w < n; w++)	 {
							float buf = a[k][w];//сохраняем строку, которую будем умножать
							if ((w == j) && (k != g)){
								//a[k][w] = a[i][j];
								int p = k; int c = w;
								//a[g][c] = lead;
								a[p][c] = buf;
							
									for (c = w; c < n; c++) {
										a[p][c] -= buf * a[g][c];
									}
								
								b[k] -= buf * b[i];

						}
					}

					i = n;
				}
			}
		}
	}

	print_matrix(n, m, a);
	for (i = 0; i < n; i++)
		cout << b[i] << "\n";

	for (i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}
