#include <stdio.h>

typedef struct {
    int rows;
    int cols;
    int data[10][10];
} Matrix;

Matrix multiplyMatrices(Matrix a, Matrix b) {
    Matrix result;
    
    if (a.cols != b.rows) {
        printf("Matrix multiplication is not valid for the given matrices.\n");
        result.rows = 0;
        result.cols = 0;
        return result;
    }

    result.rows = a.rows;
    result.cols = b.cols;

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.data[i][j] = 0;
        }
    }

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }

    return result;
}

void printMatrix(Matrix matrix) {
    if (matrix.rows == 0 || matrix.cols == 0) {
        printf("Invalid matrix.\n");
        return;
    }

    for (int i = 0; i < matrix.rows; i++) {
        printf("| ");
        for (int j = 0; j < matrix.cols; j++) {
            printf("%d ", matrix.data[i][j]);
        }
        printf("|\n");
    }
}

int main() {
    Matrix matrixA = {
        .rows = 3,
        .cols = 2,
        .data = {
            {5, -6},
            {-4, 3},
            {1, -2}
        }
    };

    Matrix matrixB = {
        .rows = 2,
        .cols = 3,
        .data = {
            {-3, 5,2},
            {1, -2, 4}
        }
    };

    Matrix matrixC = multiplyMatrices(matrixA, matrixB);

    printf("Resultant Matrix C (Multiplication):\n");
    printMatrix(matrixC);

    return 0;
}
