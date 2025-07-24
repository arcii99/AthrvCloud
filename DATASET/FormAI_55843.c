//FormAI DATASET v1.0 Category: Fractal Generation ; Style: mind-bending
#include <stdio.h>

int main() {
    int x, y, z;
    printf("Enter a value for x: ");
    scanf("%d", &x);
    printf("Enter a value for y: ");
    scanf("%d", &y);
    printf("Enter a value for z: ");
    scanf("%d", &z);

    for (int i = 0; i < 50; i++) {
        if (i % x == 0) {
            for (int j = 0; j < i; j++) {
                if (j % y == 0) {
                    printf("*");
                } else if (j % z == 0) {
                    printf("+");
                } else {
                    printf("-");
                }
            }
            printf("\n");
        } else {
            for (int j = 0; j < i; j++) {
                printf(" ");
            }
            printf("*\n");
        }
    }

    return 0;
}