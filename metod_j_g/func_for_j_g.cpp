#include <iostream>

//создание матрицы
float** create_matrix(unsigned row, unsigned column) {
	float** a = new float*[row];

	for (unsigned i = 0; i < row; i++) {
		a[i] = new float[column];
		for (unsigned j = 0; j < column; j++) {
			std::cout << "a[" << i << ", " << j << "] = ";
			std::cin >> a[i][j];
		}

	}

	return a;
}

void print_matrix(unsigned row, unsigned column, float **a) {
	for (unsigned i = 0; i < row; i++) {
		for (unsigned j = 0; j < column; j++)
			std::cout << a[i][j] << " ";
		std::cout << std::endl;
	}
}

