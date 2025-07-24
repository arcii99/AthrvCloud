//FormAI DATASET v1.0 Category: Pattern printing ; Style: Claude Shannon
#include <stdio.h>

/*
 * This program illustrates the famous Butterfly Pattern in C. 
 * It is a beautiful and mesmerizing pattern, representing the
 * elegance of C programming language.
 */

void printPattern(int n) {
    int i, j, k;

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        for(k = 1; k <= 2 * (n - i); k++) {
            printf(" ");
        }
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    for(i = n; i >= 1; i--) {
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        for(k = 1; k <= 2 * (n - i); k++) {
            printf(" ");
        }
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("\n");

    printPattern(n);
    return 0;
}