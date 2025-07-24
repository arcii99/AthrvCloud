//FormAI DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>

int main() {
    int m1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[3][3];

    printf("Hooray! Let's do some matrix operations!\n\n");

    // Matrix addition
    printf("Let's add these matrices:\n\n");
    printf("Matrix 1:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Matrix 2:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Result:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Matrix multiplication
    printf("Now let's multiply these matrices:\n\n");
    printf("Matrix 1:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Matrix 2:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    printf("Result:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Matrix transpose
    printf("Finally, let's transpose this matrix:\n\n");
    printf("Matrix:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result[j][i] = m1[i][j];
        }
    }

    printf("Result:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Yay, we did it! I love matrix operations! :)");
    return 0;
}