#include <iostream>
#include "my_array.h"
#include "my_matrix.h"
#include "my_sort.h" 
using namespace std;

int main() {
    int choice;
    do {
        cout << "Меню:\n";
        cout << "1. Завдання 1: Обробка одновимірного масиву\n";
        cout << "2. Завдання 2: Обробка матриці\n";
        cout << "3. Завдання 3: Сортування масиву\n";
        cout << "0. Вихід\n";
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
            case 1:
                task_1();
                break;
            case 2:
                task_2();
                break;
            case 3:
                task_3();
                break;
            case 0:
                cout << "Вихід\n";
                break;
            default:
                cout << "Невірний вибір, спробуйте ще раз\n";
        }
    } while (choice != 0);

    return 0;
}