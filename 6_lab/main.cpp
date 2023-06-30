#include "matrix.hpp"

int main() {
    int n;
    int matrix[100][100];

    Matrix::readMatrix(n, matrix);
    Matrix::processMatrix(n, matrix);
    Matrix::writeMatrix(n, matrix);

    return 0;
}
