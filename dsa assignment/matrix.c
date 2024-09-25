# include<stdio.h>
#include<stdlib.h>

int* allocateMatrix(int rows, int cols){
    int*matrix = (int*) malloc(rows * cols * sizeof(int));
    return matrix;
}

void freemat(int* matrix){
    free(matrix);
}

void multiplyMatrices(int* matrixA, int* matrixB, int* matrixC, int rowsA, int colsA, int colsB){
    for(int i=0;i<rowsA;i++){
        for(int j = 0; j < colsB; j++){
            matrixC[i * colsB +j] = 0;
            for(int k = 0; k < colsA; k++) {
                matrixC[i * colsB + j] += matrixA[i * colsA + k] * matrixB[k * colsB + j];
            }
        }
    }
}


void printMatrix(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++){
        for (int j = 0; j <cols; j++){
            printf("%d", matrix[i * cols + j]);
        }
        printf("\n");
    }
}


int main(){
    int rowsA, colsA, rowsB, colsB;

    printf("Enter number of rows for matrix A:");
    scanf("%d", &rowsA);
    printf("Enter number of columns for matrix A:");
    scanf("%d", &colsA);
    printf("Enter number of rows for matrix B:");
    scanf("%d", &rowsB);
    printf("Enter number of columns for matrix B:");
    scanf("%d", &colsB);

    if (colsA != rowsB){
        printf("Matrices cannot be multiplied.\n");
        return 1;
    }

    int* matrixA = allocateMatrix(rowsA, colsA);
    int* matrixB = allocateMatrix(rowsB, colsB);
    int* matrixC = allocateMatrix(rowsA, colsB);

    printf("Enter elements of matrix A: \n");
    for( int i = 0; i < rowsA; i++){
        for (  int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i * colsA + j]);
        }
        
    }

    printf("Enter elements of matrix B: \n");
    for( int i = 0; i < rowsB; i++){
        for (  int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i * colsB + j]);
        }
        
    }

    multiplyMatrices(matrixA, matrixB, matrixC, rowsA, colsA, colsB);

    printf("Matrix A:\n");
    printMatrix(matrixA, rowsA, colsA);
    printf("Matrix B:\n");
    printMatrix(matrixB, rowsB, colsB);
    printf("Matrix C (A * B):\n");
    printMatrix(matrixC, rowsA, colsB);

    freemat(matrixA);
    freemat(matrixB);
    freemat(matrixC);

    return 0;
}