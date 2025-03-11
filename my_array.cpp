#include <iostream>
#include <fstream>
#include <map>
#include "my_array.h"
using namespace std;

const int N = 50; // Максимальний розмір масиву

// Зчитування масиву з файлу
void input_arr_from_file(const string& filename, int arr[], int &n) {
    ifstream input_file(filename);
    if (!input_file) {
        cout << "Не вдалося відкрити файл для зчитування.\n";
        return;
    }
    input_file >> n;
    for (int i = 0; i < n; i++) {
        input_file >> arr[i];
    }
    input_file.close();
}

// Запис масиву у файл
void output_arr_to_file(const string& filename, const int arr[], int n) {
    ofstream output_file(filename);
    if (!output_file) {
        cout << "Не вдалося відкрити файл для запису.\n";
        return;
    }
    output_file << "Розмір масиву: " << n << "\n";
    for (int i = 0; i < n; i++) {
        output_file << arr[i] << " ";
    }
    output_file.close();
}

// Видалення елементів, що зустрічаються менше 3 разів
void remove_elements_less_than_three(int arr[], int &n) {
    map<int, int> freq;

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
    n = new_size;
}

// Завдання 1
void task_1() {
    int arr[N], n;
    string filename_in, filename_out;

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
