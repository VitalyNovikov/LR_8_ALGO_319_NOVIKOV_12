#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <string>
using namespace std;

// Прототипи функцій
void input_arr_from_file(const string& filename, int arr[], int &n);  // Зчитування з файлу
void output_arr_to_file(const string& filename, const int arr[], int n);  // Запис у файл
void remove_elements_less_than_three(int arr[], int &n);  // Видалення елементів, що зустрічаються менше 3 разів
void task_1();  // Завдання 1

#endif
