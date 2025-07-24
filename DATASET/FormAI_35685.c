//FormAI DATASET v1.0 Category: Scientific ; Style: grateful
#include <stdio.h>

// Function that recursively calculates the Fibonacci sequence
int fibonacci(int num) {
    // Base case
    if (num == 0 || num == 1) {
        return num;
    }
    // Recursive case
    else {
        return fibonacci(num-1) + fibonacci(num-2);
    }
}

int main() {
    int num_terms;
    printf("Enter the number of terms you want in the Fibonacci sequence: ");
    scanf("%d", &num_terms);

    printf("The Fibonacci sequence up to %d terms is:\n", num_terms);
    for (int i = 0; i < num_terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}