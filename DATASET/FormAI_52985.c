//FormAI DATASET v1.0 Category: Pattern printing ; Style: intelligent
#include <stdio.h>

int main() {
    int height, i, j, k;

    printf("Enter the height of the pattern: ");
    scanf("%d", &height); // height input from user

    // top part of the pattern
    for (i=1; i<=height; i++) {
        for (j=height; j>i; j--) {
            printf(" ");
        }
        for (k=1; k<=i; k++) {
            printf("%d", k);
        }
        for (k=i-1; k>=1; k--) {
            printf("%d", k);
        }
        printf("\n");
    }

    // bottom part of the pattern
    for (i=height-1; i>=1; i--) {
        for (j=height; j>i; j--) {
            printf(" ");
        }
        for (k=1; k<=i; k++) {
            printf("%d", k);
        }
        for (k=i-1; k>=1; k--) {
            printf("%d", k);
        }
        printf("\n");
    }

    return 0;
}