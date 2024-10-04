#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

// Функция инициализации одномерного массива случайными числами
void initializeArray(int* arr, int size) {
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 201 - 100; // Случа числа от -100 до 100
    }
}

// Функция вывода одномерного массива на экран
void print1DArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << setw(5) << arr[i];
    }
    cout << endl;
}

// Функция вывода двумерного массива на экран
void print2DArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << arr[i][j];
        }
        cout << endl;
    }
}

// Функция преобразования одномерного массива в двумерный
void convert1DTo2D(int* arr1D, int** arr2D, int rows, int cols) {
    sort(arr1D, arr1D + rows * cols, greater<int>());
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr2D[i][j] = arr1D[i * cols + j];
        }
    }
}

int main() {
    std::setlocale(LC_ALL, "Russian");
    const int size = 18;
    const int rows = 9;
    const int cols = 2;

    // Выделение памяти для одномерного массива
    int* arr1D = new int[size];

    // Инициализация одномерного массива случайными числами
    initializeArray(arr1D, size);

    // Вывод одномерного массива на экран
    cout << "Одномерный массив:" << endl;
    print1DArray(arr1D, size);

    // Выделение памяти для двумерного массива
    int** arr2D = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr2D[i] = new int[cols];
    }

    // Преобразование одномерного массива в двумерный
    convert1DTo2D(arr1D, arr2D, rows, cols);

    // Вывод двумерного массива на экран
    cout << "Двумерный массив:" << endl;
    print2DArray(arr2D, rows, cols);

    // Код для свобождение памяти
    delete[] arr1D;
    for (int i = 0; i < rows; ++i) {
        delete[] arr2D[i];
    }
    delete[] arr2D;

    return 0;
}

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <locale>

char* my_strcpy(char* dest, const char* src) {
    char* original_dest = dest;
    while ((*dest++ = *src++) != '\0');
    return original_dest;
}

// Функция для генерации случайной строки из цифр и букв
void generateRandomString(char* str, int length) {
    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    srand(time(0));
    for (int i = 0; i < length; ++i) {
        int key = rand() % (sizeof(charset) - 1);
        str[i] = charset[key];
    }
    str[length] = '\0';
}

int main() {
    std::setlocale(LC_ALL, "Russian");
    const int length = 10;
    char src[length + 1];
    char dest1[length + 1];
    char dest2[length + 1];

    generateRandomString(src, length);

    strcpy(dest1, src);
    printf("Стандартная strcpy: %s\n", dest1);

    my_strcpy(dest2, src);
    printf("Собственная my_strcpy: %s\n", dest2);

    return 0;
}
*/
