//FormAI DATASET v1.0 Category: Recursive ; Style: careful
#include <stdio.h>

// Recursive function to calculate the factorial of a number
int factorial(int number) {
    if (number == 0 || number == 1) { // Base case
        return 1;
    } else {
        return number * factorial(number - 1); // Recursive case
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int fact = factorial(num); // Call the recursive function

    printf("Factorial of %d is %d", num, fact);

    return 0;
}