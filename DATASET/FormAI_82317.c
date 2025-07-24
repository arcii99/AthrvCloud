//FormAI DATASET v1.0 Category: Educational ; Style: mathematical
#include <stdio.h>

int main() {
    printf("Welcome to the Mathematical Series program!\n");

    int i, n;
    float sum = 0;
    printf("Enter the number of terms in the series: ");
    scanf("%d", &n);

    printf("The series is: ");
    for (i = 1; i <= n; i++) {
        printf("1/%d + ", i); // Prints the series 1/1 + 1/2 + ... + 1/n
        sum += (float)1/i; // Adds the current series term to the sum
    }

    printf("\n\nThe sum of the series is: %f", sum); // Prints the sum of the series
    
    printf("\n\nNow, let's evaluate the Fibonacci Series!\n");
    int count, first_term = 0, second_term = 1, next_term;

    printf("Enter the number of terms you want: ");
    scanf("%d", &count);

    printf("\nThe Fibonacci Series is: %d, %d, ", first_term, second_term); // Prints the first two terms of the series

    for (i = 3; i <= count; i++) {
        next_term = first_term + second_term; // Calculates the next term in the series
        printf("%d, ", next_term); // Prints the next term
        first_term = second_term; // Updates the values for the next iteration
        second_term = next_term;
    }

    printf("\n\nThat's all for the Mathematical Series program! Thanks for using it!");

    return 0;
}