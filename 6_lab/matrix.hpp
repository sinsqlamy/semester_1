#pragma once
#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace Matrix {
    // Структура строки матрицы
    struct Row {
        int index;
        int sum;
    };

    // Функция чтения матрицы
    void readMatrix(int& n, int matrix[][100]);

    // Функция проверки, является ли число простым
    bool isPrime(int n);

    // Функция проверки наличия двух одинаковых столбцов и простого числа
    bool hasDuplicateColumnsAndPrime(int n, int matrix[][100], int& col1, int& col2);

    // Функция обработки матрицы и упорядочивания строк
    void processMatrix(int n, int matrix[][100]);

    // Функция записи матрицы
    void writeMatrix(int n, int matrix[][100]);
}

#endif  // MATRIX_HPP
