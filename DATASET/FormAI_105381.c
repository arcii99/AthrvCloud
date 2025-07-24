//FormAI DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>

/* Function for computing the factorial of a given integer */
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

/* A function for computing the combinations using the formula nCk = n!/k!(n-k)! */
int combinations(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

/* A function for computing the permutations using the formula nPk = n!/(n-k)! */
int permutations(int n, int k) {
    return factorial(n) / factorial(n - k);
}

int main() {
    int n, k;

    /* Read in the input values for n and k from the user */
    printf("Enter the value for n: ");
    scanf("%d", &n);
    printf("Enter the value for k: ");
    scanf("%d", &k);

    /* Compute and output the combinations and permutations */
    printf("%dC%d = %d\n", n, k, combinations(n, k));
    printf("%dP%d = %d\n", n, k, permutations(n, k));

    return 0;
}