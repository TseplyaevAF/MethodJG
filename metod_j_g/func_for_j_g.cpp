#include <iostream>

//�������� �������
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
//����� �������
void print_matrix(unsigned row, unsigned column, float **a) {
	for (unsigned i = 0; i < row; i++) {
		for (unsigned j = 0; j < column; j++)
			std::cout << a[i][j] << " ";
		std::cout << std::endl;
	}
}

//�������� �� ��������� ������ � ������
bool check_line(unsigned id_row, float** matrix, unsigned old) {
	if (old == 0)
	{
		old = id_row;
		return 0;
	}
	if (old != id_row)
		return 0; else
		return 1;
}