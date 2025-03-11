#include <iostream>
#include <fstream>
#include "my_sort.h"
using namespace std;

// Сортування методом вставки для масиву символів
void insertionSort(char arr[], int n) {
    for (int i = 1; i < n; ++i) {
        char key = arr[i];
        int j = i - 1;

        // Переміщуємо елементи масиву, що більші за key, на одну позицію вправо
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Зчитування масиву з файлу
bool readArrayFromFile(const string& filename, char arr[], int& n) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Не вдалося відкрити файл для зчитування!" << endl;
        return false;
    }

    n = 0;
    while (inputFile >> arr[n]) {
        ++n;
    }

    inputFile.close();
    return true;
}

// Виведення масиву
void printArray(const char arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Завдання 3: Сортування масиву
void task_3() {
    const int MAX_SIZE = 7;  // Максимальна кількість елементів
    char arr[MAX_SIZE];
    int n;

    string filename;
    cout << "Введіть ім'я файлу для зчитування масиву: ";
    cin >> filename;

    // Зчитуємо масив з файлу
    if (!readArrayFromFile(filename, arr, n)) {
        return;
    }

    cout << "Масив до сортування: ";
    printArray(arr, n);

    // Сортуємо масив методом вставки
    insertionSort(arr, n);

    cout << "Відсортований масив: ";
    printArray(arr, n);
}
