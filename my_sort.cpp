#include <iostream>
#include <fstream>  // Підключення бібліотеки для роботи з файлами
#include "my_sort.h"
using namespace std;

// Сортування методом вставки для масиву символів
void insertionSort(char arr[], int n) {
    for (int i = 1; i < n; ++i) {   // Починаємо з другого елемента
        char key = arr[i];   // Зберігаємо поточний елемент
        int j = i - 1;

        // Переміщуємо елементи масиву, що більші за key, на одну позицію вправо
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;   // Вставляємо key на знайдену позицію
    }
}

// Зчитування масиву з файлу
bool readArrayFromFile(const string& filename, char arr[], int& n) {
    ifstream inputFile(filename);   // Відкриття файлу для зчитування
    if (!inputFile) {   // Перевірка, чи файл відкрито успішно
        cerr << "Не вдалося відкрити файл для зчитування!" << endl;
        return false;
    }

    n = 0;  // Ініціалізація лічильника елементів
    while (inputFile >> arr[n]) {   // Зчитування символів до кінця файлу
        ++n;
    }

    inputFile.close();  // Закриття файлу
    return true;
}

// Виведення масиву
void printArray(const char arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";  // Вивід кожного елемента з пробілом
    }
    cout << endl;
}

// Завдання 3: Сортування масиву
void task_3() {
    const int MAX_SIZE = 7;  // Максимальна кількість елементів
    char arr[MAX_SIZE];     // Масив для зберігання символів
    int n;      // Кількість зчитаних елементів

    string filename;
    cout << "Введіть ім'я файлу для зчитування масиву: ";
    cin >> filename;    // Зчитування імені файлу з консолі

    // Зчитуємо масив з файлу
    if (!readArrayFromFile(filename, arr, n)) {
        return;     // Вихід, якщо зчитування не вдалося
    }

    cout << "Масив до сортування: ";
    printArray(arr, n);     // Виведення масиву до сортування

    // Сортуємо масив методом вставки
    insertionSort(arr, n);      // Сортування масиву методом вставки

    cout << "Відсортований масив: ";
    printArray(arr, n);     // Виведення відсортованого масиву
}
