//FormAI DATASET v1.0 Category: Matrix operations ; Style: surprised
#include <stdio.h>

int main() {
    printf("Hold on to your hats, folks! We're about to perform some matrix operations!\n");

    // Matrix A
    int A[3][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};

    // Matrix B
    int B[3][3] = {{9, 8, 7},
                   {6, 5, 4},
                   {3, 2, 1}};

    printf("Matrix A:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("Let's add them up! Here's the result of A + B:\n");
    int C[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    printf("And now, let's subtract them. Here's the result of A - B:\n");
    int D[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            D[i][j] = A[i][j] - B[i][j];
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }

    printf("Whoa, it's not over yet! Let's multiply them now. Here's the result of A * B:\n");
    int E[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            E[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                E[i][j] += A[i][k] * B[k][j];
            }
            printf("%d ", E[i][j]);
        }
        printf("\n");
    }

    printf("Oh yeah, we just multiplied them like a boss.\n");

    return 0;
}