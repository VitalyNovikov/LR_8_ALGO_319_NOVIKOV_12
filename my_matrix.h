#ifndef MY_MATRIX_H
#define MY_MATRIX_H

#include <string>
using namespace std;

// Прототипи функцій
void get_matrix_from_file(const string& filename, int matr[20][20], int &rows, int &cols);  // Зчитування з файлу
void output_matrix_to_file(const string& filename, const int matr[20][20], int rows, int cols);  // Запис у файл
int find_special_element(const int matr[20][20], int rows, int cols);  // Пошук спеціального елемента
void task_2();  // Завдання 2

#endif
