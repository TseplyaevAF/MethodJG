#pragma once
//создание матрицы
float ** create_matrix(unsigned row, unsigned column);

//вывод матрицы
void print_matrix(unsigned row, unsigned column, float ** a);

//проверка на вхождение строки в массив
bool check_line(unsigned id_row, float **matrix);

//вычитание строк
float vich_strok(float **matrix, float a_div_lead, unsigned id_row);