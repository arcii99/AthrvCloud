//FormAI DATASET v1.0 Category: Pattern printing ; Style: careful
#include <stdio.h>

int main() {
    int height, i, j, k;
    printf("Enter the height of the pattern: ");
    scanf("%d", &height);

    // Upper part of the pattern
    for(i = 0; i < height/2; i++) {
        for(j = 0; j < i; j++) {
            printf(" ");
        }
        for(k = 0; k < height - (2*i); k++) {
            printf("*");
        }
        printf("\n");
    }

    // Middle line of the pattern
    for(i = 0; i < height/2; i++) {
        printf(" ");
    }
    printf("*\n");

    // Lower part of the pattern
    for(i = height/2 - 1; i >= 0; i--) {
        for(j = 0; j < i; j++) {
            printf(" ");
        }
        for(k = 0; k < height - (2*i); k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}