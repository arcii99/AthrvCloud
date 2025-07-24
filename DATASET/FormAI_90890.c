//FormAI DATASET v1.0 Category: Computer Biology ; Style: mathematical
#include <stdio.h>

// define a function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    // take input from user
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // calculate the combination of n choose k
    int k;
    int comb = 0;
    for (k=0; k<=n; k++) {
        comb += factorial(n) / (factorial(n-k) * factorial(k));
    }

    // output the result to the user
    printf("The combination of n choose k is: %d\n", comb);

    return 0;
}