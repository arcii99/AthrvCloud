//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>
int main() {
    printf("Welcome to the world of C Pattern printing!!\n");
    int i, j, k, n;
    printf("Enter the number of rows for your exciting pattern: ");
    scanf("%d", &n);
    printf("You are going to love the pattern!! Here it goes:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            printf("*");
        }
        for (k = 0; k < i; k++) {
            printf(" ");
        }
        for (k = 0; k < i - 1; k++) {
            printf(" ");
        }
        for (j = 0; j < n - i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("*");
        }
        for (k = i; k < n - 1; k++) {
            printf(" ");
        }
        for (k = i + 1; k < n - 1; k++) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("WOW!! That was amazing, right?\n");
    return 0;
}