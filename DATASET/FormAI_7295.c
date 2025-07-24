//FormAI DATASET v1.0 Category: Pattern printing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i, j, k;
    char pattern;
    printf("Enter the size of the pattern (odd number only): ");
    scanf("%d", &size);
    getchar();
    printf("Enter a character for the pattern: ");
    scanf("%c", &pattern);
    getchar();
    if (size%2==0) {
        printf("Size should be an odd number. Please try again.");
        exit(0);
    }
    printf("Preparing to print...\n\n");
    for (i=1; i<=size/2+1; i++) {
        for (j=1; j<=size; j++) {
            if (j<i || j>size-i+1) {
                printf("%c", pattern);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (i=size/2; i>=1; i--) {
        for (j=1; j<=size; j++) {
            if (j<i || j>size-i+1) {
                printf("%c", pattern);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Pattern printed successfully!");
    return 0;
}