//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: future-proof
#include <stdio.h>

void fibonacci_visualizer(int n) {
    int first_term = 0, second_term = 1, next_term;

    // Printing the first two terms
    printf("%d %d ", first_term, second_term);

    for(int i=2; i<n; i++) {
        next_term = first_term + second_term;
        first_term = second_term;
        second_term = next_term;

        // Printing visualization of Fibonacci sequence
        for(int j=0; j<next_term; j++) {
            printf("*");
        }

        printf(" %d\n", next_term);
    }
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if(n < 2) {
        printf("Number of terms should be greater than or equal to 2\n");
    } else {
        fibonacci_visualizer(n);
    }

    return 0;
}