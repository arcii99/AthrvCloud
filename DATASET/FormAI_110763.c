//FormAI DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>

// function to calculate the factorial of a number
int factorial(int num) {
    int fact = 1;
    for(int i=1; i<=num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    // declare variables
    int n, i, j, k;

    // get user input
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // loop to print the pyramid
    for(i=1; i<=n; i++) {
        for(j=n; j>i; j--) {
            printf(" ");
        }
        for(k=1; k<=i; k++) {
            printf("%d ", factorial(i)/(factorial(k)*factorial(i-k)));
        }
        printf("\n");
    }
    return 0;
}