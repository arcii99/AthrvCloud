//FormAI DATASET v1.0 Category: Pattern printing ; Style: invasive
#include <stdio.h>

int main() {
    printf("Hello! I am here to print a unique C pattern for you.\n");

    for (int i = 0; i < 10; i++) {
        printf("C");

        if (i == 0 || i == 9) {
            for (int j = 0; j < 6; j++) {
                printf("C");
            }
        } else if (i == 1 || i == 8) {
            for (int j = 0; j < 5; j++) {
                printf(" ");
            }
            for (int k = 0; k < 2; k++) {
                printf("C");
            }
        } else if (i == 2 || i == 7) {
            for (int j = 0; j < 5; j++) {
                if (j == 0 || j == 4) {
                    printf("C");
                } else {
                    printf(" ");
                }
            }
        } else if (i == 3 || i == 6) {
            for (int j = 0; j < 5; j++) {
                if (j == 0) {
                    printf("C");
                } else if (j == 4) {
                    printf(" ");
                } else {
                    printf("-");
                }
            }
        } else if (i == 4 || i == 5) {
            for (int j = 0; j < 5; j++) {
                if (j == 0 || j == 4) {
                    printf("C");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}