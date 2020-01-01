#pragma once
//создание матрицы
float ** create_matrix(unsigned n);

//вывод матрицы
void print_matrix(unsigned n, float ** a);

//проверка на вхождение строки в массив
bool check_line(unsigned id_row, unsigned old);