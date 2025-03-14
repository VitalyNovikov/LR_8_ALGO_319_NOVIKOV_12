#include <iostream>
#include <fstream>      // Підключення бібліотеки для роботи з файлами
#include "my_matrix.h"
using namespace std;

const int M = 20, N = 20; // Максимальні розміри матриці

// Зчитування матриці з файлу
void get_matrix_from_file(const string& filename, int matr[M][N], int &rows, int &cols) {
    ifstream input_file(filename);  // Відкриття файлу для зчитування
    if (!input_file) {  // Перевірка на успішне відкриття файлу
        cout << "Не вдалося відкрити файл для зчитування матриці.\n";
        return;
    }
    input_file >> rows >> cols; // Зчитування кількості рядків і стовпців матриці
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            input_file >> matr[i][j];   // Зчитування елементів матриці
        }
    }
    input_file.close(); // Закриття файлу
}

// Запис матриці у файл
void output_matrix_to_file(const string& filename, const int matr[M][N], int rows, int cols) {
    ofstream output_file(filename); // Відкриття файлу для запису
    if (!output_file) { // Перевірка на успішне відкриття файлу
        cout << "Не вдалося відкрити файл для запису матриці.\n";
        return;
    }
    // Запис елементів матриці у файл
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            output_file << matr[i][j] << " ";   // Запис елемента з пробілом
        }
        output_file << endl;    // Перехід на новий рядок після кожного ряду
    }
    output_file.close();     // Закриття файлу
}

// Пошук спеціального елемента
int find_special_element(const int matr[M][N], int rows, int cols) {
    // Проходимо кожен елемент матриці
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool isMaxInRow = true, isMinInCol = true;

            // Перевіряємо, чи є поточний елемент максимальним у своєму рядку
            for (int k = 0; k < cols; k++)
                if (matr[i][k] > matr[i][j]) isMaxInRow = false;

            // Перевіряємо, чи є поточний елемент мінімальним у своєму стовпці
            for (int k = 0; k < rows; k++)
                if (matr[k][j] < matr[i][j]) isMinInCol = false;

            // Якщо обидві умови виконуються, повертаємо цей елемент
            if (isMaxInRow && isMinInCol) return matr[i][j];
        }
    }
    return 0;   // Якщо такого елемента немає, повертаємо 0
}

// Завдання 2
void task_2() {
    int matr[M][N], rows, cols; // Оголошення матриці та змінних для розмірів
    string filename_in, filename_out;   // Змінні для зберігання імен файлів

    // Введення імен файлів
    cout << "Введіть ім'я вхідного файлу для матриці: ";
    cin >> filename_in;
    cout << "Введіть ім'я вихідного файлу для матриці: ";
    cin >> filename_out;

    // Зчитування матриці з файлу
    get_matrix_from_file(filename_in, matr, rows, cols);

    // Пошук спеціального елемента
    int special_element = find_special_element(matr, rows, cols);
    
    // Запис результату в файл
    output_matrix_to_file(filename_out, matr, rows, cols);
    cout << "Спеціальний елемент: " << (special_element ? to_string(special_element) : "0") << endl;
}
