#include <stdio.h>
#define ROWS_A 3
#define COLS_A 2
#define ROWS_B 2
#define COLS_B 4

void matrixMultiply(int A[][COLS_A], int B[][COLS_B], int C[][COLS_B], int rowsA, int colsA, int colsB) {int i,j,k;
    for ( i = 0; i < rowsA; i++) {
        for ( j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for ( k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int matrix[][COLS_B], int rows, int cols) {int i,j;
    for ( i = 0; i < rows; i++) {
        for ( j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrixA[ROWS_A][COLS_A] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };

    int matrixB[ROWS_B][COLS_B] = {
        {7, 8, 9, 10},
        {11, 12, 13, 14}
    };

    int resultMatrix[ROWS_A][COLS_B];

    matrixMultiply(matrixA, matrixB, resultMatrix, ROWS_A, COLS_A, COLS_B);

    printf("Matrix A:\n");
    printf("MATRIXA,ROWS_A,COLS_A");

    printf("\nMatrix B:\n");
    printMatrix(matrixB, ROWS_B, COLS_B);

    printf("\nResultant Matrix C:\n");
    printMatrix(resultMatrix, ROWS_A, COLS_B);

    return 0;
}

