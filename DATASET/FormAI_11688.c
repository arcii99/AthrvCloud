//FormAI DATASET v1.0 Category: Pattern printing ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    int n = 9;  // Change this number to adjust the size of the magnifying glass
    int i, j;

    // Print the top half of the magnifying glass
    for (i = 0; i < n/2; i++) {
        for (j = 0; j < n; j++) {
            if (j == (n/2)-1-i || j == (n/2)+1+i) {
                printf("*");
            } else if (i == 0 && j % 2 == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Print the middle part of the magnifying glass
    for (i = 0; i < n/4; i++) {
        for (j = 0; j < n/2-1; j++) {
            printf(" ");
        }
        printf("*");
        for (j = 0; j < n/2-2; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    // Print the bottom half of the magnifying glass
    for (i = n/2-1; i >= 0; i--) {
        for (j = 0; j < n; j++) {
            if (j == (n/2)-1-i || j == (n/2)+1+i) {
                printf("*");
            } else if (i == 0 && j % 2 == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}