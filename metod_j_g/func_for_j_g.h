#pragma once
//�������� �������
float ** create_matrix(unsigned row, unsigned column);

//����� �������
void print_matrix(unsigned row, unsigned column, float ** a);

//�������� �� ��������� ������ � ������
bool check_line(unsigned id_row, float **matrix);

//��������� �����
float vich_strok(float **matrix, float a_div_lead, unsigned id_row);