//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Let's print a C pattern!

    printf("\n\n");

    for (int i = 1; i <= 5; ++i) {

        // Let's print the 'C'

        for (int j = 1; j <= 5; ++j) {

            if (i == 1 || i == 5) {
                printf("*");
            }
            else if (j == 1) {
                printf("*");
            }
            else if (i == 2 && j == 4) {
                printf("*");
            }
            else if (i == 3 && j == 4) {
                printf("*");
            }
            else if (i == 4 && j == 4) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }

        // Let's print some more 'C's!
        
        printf("    ");

        for (int j = 1; j <= 5; ++j) {

            if (i == 1 || i == 5) {
                printf("*");
            }
            else if (j == 1) {
                printf("*");
            }
            else if (i == 2 && j == 4) {
                printf("*");
            }
            else if (i == 3 && j == 4) {
                printf("*");
            }
            else if (i == 4 && j == 4) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }

        printf("\n");
    }

    printf("\n");

    return 0;
}