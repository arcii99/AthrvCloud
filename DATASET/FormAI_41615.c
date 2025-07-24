//FormAI DATASET v1.0 Category: Pattern printing ; Style: multivariable
#include<stdio.h>

int main() {
    int i, j, k;

    // First C
    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 5; j++) {
            if (j == 1 || i == 1 || i == 8) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");

    // Second C
    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 5; j++) {
            if (j == 1 || i == 1 || i == 8 || j == 5 && i > 2 && i < 8) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");

    // Third C
    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 5; j++) {
            if (j == 1 || i == 1 || i == 8 || j == 5 && i < 8 && i > 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");

    // Fourth C
    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 5; j++) {
            if (j == 5 || i == 1 || i == 8) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");

    // Fifth C
    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 5; j++) {
            if (j == 5 || i == 1 || i == 8 || j == 1 && i > 1 && i < 8) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");

    // Sixth C
    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 5; j++) {
            if (j == 5 || i == 1 || i == 8 || j == 1 && i < 8 && i > 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");

    // Seventh C
    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 5; j++) {
            if (j == 1 && i < 8 && i > 1 || j == 5 && i > 1 || i == 1 || i == 8) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");

    // Eighth C
    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 5; j++) {
            if (j == 1 && i > 1 || j == 5 && i < 8 && i > 1 || i == 1 || i == 8) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");

    // Ninth C
    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 5; j++) {
            if (j == 1 && i > 1 || j == 5 && i > 1 || i == 1 || i == 8 && j > 1 && j < 5) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");

    // Tenth C
    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 5; j++) {
            if (j == 1 && i < 8 || j == 5 && i > 1 || i == 1 || i == 8 && j > 1 && j < 5) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}