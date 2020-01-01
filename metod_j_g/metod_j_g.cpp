#include <iostream>
#include <math.h>
#include "func_for_j_g.h"

using namespace std;

int main()
{
	float** a; unsigned n, i, j; float b[10];
	unsigned id_row, id_row_old = 1; int k, g = 0; float lead;
	setlocale(LC_ALL, "Rus");

	cout << "Введите порядок матрицы: ";
	cin >> n;
	a = create_matrix(n);

	//заполнение столбца свободных членов
	for (i = 0; i < n; i++) {
		cout << "b[" << i << "] = ";
		cin >> b[i];
	}

	print_matrix(n, a);
	for (i = 0; i < n; i++)
		cout << b[i] << "\n";
	cout << endl;
	//поиск ненулевого элемента в столбце
	for (j = 0; j < n; j++) {
		for (i = g; i < n; i++) {
			if (a[i][j] != 0)
			{
				id_row = i;//запоминаем номер строки
				unsigned flag = check_line(id_row, id_row_old);
				if (flag == 0) {//если текущая строка не была использована
					id_row_old = id_row;
					lead = a[i][j];//выбираем первый входящий в нее элемент
					for (k = j; k < n; k++) 
						a[i][k] /= lead; //делим всю строку на него
					b[i] /= lead;
					
					g = i; 
					//вычитание строк
					for (k = 0; k < n; k++)
					for (int w = 0; w < n; w++)	 {
							float buf = a[k][w];//сохраняем элемент строки, который будет множителем 
							if ((w == j) && (k != g)){
								int p = k; int c = w;
								a[p][c] = buf;//сохраняем строку
							
									for (c = w; c < n; c++) {
										a[p][c] -= buf * a[g][c];
									}
								
								b[k] -= buf * b[i];

						}
					}

					i = n;//для перехода к след. столбцу
				}
			}
		}
	}

	print_matrix(n, a); //вывод матрицы
	for (i = 0; i < n; i++)//вывод результата
		cout << "x" << i+1 << " = " << b[i] << "\n";

	for (i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;

	system("pause");

	return 0;
}
