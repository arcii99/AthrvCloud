//FormAI DATASET v1.0 Category: Matrix operations ; Style: statistical
// This program performs matrix operations in a statistical style
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function to read matrix from input
void readMatrix(float *A, int M, int N) {
    int i, j;
    printf("Enter the matrix of size %dx%d:\n", M, N);
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            scanf("%f", A+i*N+j);
        }
    }
}

//function to print matrix to output
void printMatrix(float *A, int M, int N) {
    int i, j;
    printf("\nThe matrix is:\n");
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            printf("%f ", *(A+i*N+j));
        }
        printf("\n");
    }
}

//function to calculate mean of a matrix
float mean(float *A, int M, int N) {
    int i, j;
    float sum=0;
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            sum += *(A+i*N+j);
        }
    }
    return sum/(M*N);
}

//function to calculate standard deviation of a matrix
float standardDeviation(float *A, int M, int N) {
    int i, j;
    float meanValue = mean(A, M, N);
    float sumOfSquares=0;
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            sumOfSquares += pow(*(A+i*N+j)-meanValue, 2);
        }
    }
    return sqrt(sumOfSquares/(M*N-1));
}

//function to calculate covariance of two matrices
float covariance(float *A, float *B, int M, int N) {
    int i, j;
    float meanA = mean(A, M, N);
    float meanB = mean(B, M, N);
    float sumOfProducts=0;
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            sumOfProducts += (*(A+i*N+j)-meanA)*(*(B+i*N+j)-meanB);
        }
    }
    return sumOfProducts/(M*N-1);
}

int main() {
    int M, N;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d",&M, &N);
    float *A = (float *)calloc(M*N, sizeof(float));
    float *B = (float *)calloc(M*N, sizeof(float));
    readMatrix(A, M, N);
    readMatrix(B, M, N);
    printMatrix(A, M, N);
    printMatrix(B, M, N);
    float cov = covariance(A, B, M, N);
    printf("\nThe covariance of the two matrices is: %f", cov);
    float stdDev = standardDeviation(A, M, N);
    printf("\nThe standard deviation of matrix A is: %f", stdDev);
    stdDev = standardDeviation(B, M, N);
    printf("\nThe standard deviation of matrix B is: %f", stdDev);
    free(A);
    free(B);
    return 0;
}