//FormAI DATASET v1.0 Category: Pattern printing ; Style: modular
#include <stdio.h>

// function to print the upper half of the pattern
void upperHalf(int n) {
    int i, j, k;
    for (i = 1; i <= n/2 + 1; i++) {
        for (j = i; j <= n/2; j++) {
            printf(" ");
        }
        for (k = 1; k <= 2*i-1; k++) {
            printf("*");
        }
        printf("\n");
    }
}

// function to print the lower half of the pattern
void lowerHalf(int n) {
    int i, j, k;
    for (i = n/2; i >= 1; i--) {
        for (j = n/2; j >= i; j--) {
            printf(" ");
        }
        for (k = 1; k <= 2*i-1; k++) {
            printf("*");
        }
        printf("\n");
    }
}

// main function
int main() {
    int n;
    printf("Enter an odd integer greater than or equal to 5: ");
    scanf("%d", &n);
    while (n < 5 || n % 2 == 0) {
        printf("Invalid input. Please enter an odd integer greater than or equal to 5: ");
        scanf("%d", &n);
    }
    printf("\n");
    upperHalf(n);
    lowerHalf(n);
    return 0;
}