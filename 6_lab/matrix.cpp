#include "matrix.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

namespace Matrix {
    void readMatrix(int& n, int matrix[][100]) {
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> matrix[i][j];
            }
        }
    }

    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    bool hasDuplicateColumnsAndPrime(int n, int matrix[][100], int& col1, int& col2) {
        for (int j1 = 0; j1 < n - 1; j1++) {
            for (int j2 = j1 + 1; j2 < n; j2++) {
                bool foundPrime = false;
                for (int i = 0; i < n; i++) {
                    if (abs(matrix[i][j1]) == abs(matrix[i][j2]) && isPrime(abs(matrix[i][j1]))) {
                        foundPrime = true;
                        break;
                    }
                }
                if (foundPrime) {
                    col1 = j1;
                    col2 = j2;
                    return true;
                }
            }
        }
        return false;
    }

    bool compareRows(const Row& r1, const Row& r2) {
        return r1.sum < r2.sum;
    }

    // Упорядочивает строки матрицы по сумме модулей элементов, если есть одинаковые столбцы и простые числа
    void processMatrix(int n, int matrix[][100]) {
        int col1, col2;
        if (hasDuplicateColumnsAndPrime(n, matrix, col1, col2)) {
            Row rows[100];
            for (int i = 0; i < n; i++) {
                int sum = abs(matrix[i][col1]) + abs(matrix[i][col2]);
                rows[i] = { i, sum };
            }
            std::sort(rows, rows + n, compareRows);
            int sortedMatrix[100][100];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    sortedMatrix[i][j] = matrix[rows[i].index][j];
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = sortedMatrix[i][j];
                }
            }
        }
    }

    void writeMatrix(int n, int matrix[][100]) {
        std::cout << "Sorted matrix:" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}
