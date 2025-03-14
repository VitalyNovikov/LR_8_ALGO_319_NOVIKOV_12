#include <iostream>
#include <fstream>  // Підключення бібліотеки для роботи з файлами
#include <map>      // Підключення бібліотеки для використання структури map
#include "my_array.h"
using namespace std;

const int N = 50; // Максимальний розмір масиву

// Зчитування масиву з файлу
void input_arr_from_file(const string& filename, int arr[], int &n) {
    ifstream input_file(filename);      // Відкриття файлу для зчитування
    if (!input_file) {      // Перевірка на успішне відкриття файлу
        cout << "Не вдалося відкрити файл для зчитування.\n";
        return;
    }
    input_file >> n;        // Зчитування кількості елементів масиву
    for (int i = 0; i < n; i++) {
        input_file >> arr[i];        // Зчитування елементів масиву
    }
    input_file.close(); // Закриття файлу
}

// Запис масиву у файл
void output_arr_to_file(const string& filename, const int arr[], int n) {
    ofstream output_file(filename);     // Відкриття файлу для запису
    if (!output_file) {     // Перевірка на успішне відкриття файлу
        cout << "Не вдалося відкрити файл для запису.\n";
        return;
    }
    output_file << "Розмір масиву: " << n << "\n";  // Запис розміру масиву у файл
    for (int i = 0; i < n; i++) {
        output_file << arr[i] << " ";   // Запис елементів масиву у файл
    }
    output_file.close();    // Закриття файлу
}

// Видалення елементів, що зустрічаються менше 3 разів
void remove_elements_less_than_three(int arr[], int &n) {
    map<int, int> freq;    // Створення словника для підрахунку частоти елементів

    // Підрахунок частоти кожного елемента
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Формування нового масиву
    int new_arr[N], new_size = 0;
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] >= 3) {
            new_arr[new_size++] = arr[i];
        }
    }

    // Оновлення вихідного масиву
    for (int i = 0; i < new_size; i++) {
        arr[i] = new_arr[i];
    }
    n = new_size;   // Оновлення розміру масиву
}

// Завдання 1
void task_1() {
    int arr[N], n;  // Оголошення масиву та змінної для його розміру
    string filename_in, filename_out;   // Змінні для зберігання імен файлів

    // Введення імен файлів
    cout << "Введіть ім'я вхідного файлу: ";
    cin >> filename_in;
    cout << "Введіть ім'я вихідного файлу: ";
    cin >> filename_out;

    // Зчитування масиву з файлу
    input_arr_from_file(filename_in, arr, n);

    // Обробка масиву: видалення елементів, що зустрічаються менше 3 разів
    remove_elements_less_than_three(arr, n);

    // Виведення результату в файл
    output_arr_to_file(filename_out, arr, n);
}
