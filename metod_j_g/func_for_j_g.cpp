#include <iostream>

//создание матрицы
float** create_matrix(unsigned n) {
	float** a = new float*[n];

	for (unsigned i = 0; i < n; i++) {
		a[i] = new float[n];
		for (unsigned j = 0; j < n; j++) {
			std::cout << "a[" << i << ", " << j << "] = ";
			std::cin >> a[i][j];
		}

	}

	return a;
}
//вывод матрицы
void print_matrix(unsigned n, float **a) {
	for (unsigned i = 0; i < n; i++) {
		for (unsigned j = 0; j < n; j++)
			std::cout << a[i][j] << " ";
		std::cout << std::endl;
	}
}

//проверка на вхождение строки в массив
bool check_line(unsigned id_row, unsigned old) {
	if (old != id_row) 
		return 0;
 else
		return 1;
}