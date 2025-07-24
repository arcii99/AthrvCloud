//FormAI DATASET v1.0 Category: Pattern printing ; Style: Alan Touring
// Alan Turing Pattern Printing Program

#include <stdio.h>

int main() {
    int height, width;

    printf("Enter the height of the pattern: ");
    scanf("%d", &height);
    printf("Enter the width of the pattern: ");
    scanf("%d", &width);

    for(int i = 0; i < height; i++) {

        // Print spaces before asterisks
        for(int j = 0; j < width - i; j++) {
            printf(" ");
        }

        // Print asterisks
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i || i == height - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        // Print spaces after asterisks
        for(int j = 0; j < width - i; j++) {
            printf(" ");
        }

        // Print asterisks again
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i || i == height - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}