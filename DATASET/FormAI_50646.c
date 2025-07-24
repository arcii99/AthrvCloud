//FormAI DATASET v1.0 Category: Pattern printing ; Style: cheerful
#include <stdio.h>

int main() {
    int size, i, j;

    printf("Let's print out a fun C pattern!\n");
    printf("Enter the size of the pattern (an odd number greater than or equal to 5): ");
    scanf("%d", &size);

    if (size < 5 || size % 2 == 0) {
        printf("Oops! The size must be an odd number greater than or equal to 5. Try again!\n");
    } else {
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                if (i == 0 || i == size - 1) {
                    if (j > 0 && j < size - 2) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                } else if (j == 0 || j == size - 2) {
                    printf("*");
                } else if (i == size / 2 && j > 1 && j < size - 2) {
                    printf("C");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    printf("Thanks for trying out our C pattern program! Have a great day!\n");

    return 0;
}