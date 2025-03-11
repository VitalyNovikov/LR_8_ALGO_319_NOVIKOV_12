#ifndef MY_SORT_H
#define MY_SORT_H

#include <string>
using namespace std;

// Прототипи функцій
void insertionSort(char arr[], int n); // Функція сортування методом вставки
bool readArrayFromFile(const string& filename, char arr[], int& n); // Зчитування масиву з файлу
void printArray(const char arr[], int n); // Виведення масиву

void task_3();  // Завдання 3: Виконання сортування

#endif
