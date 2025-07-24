//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include <stdio.h>

void printFibonacci(int n) {
    int firstNumber = 0, secondNumber = 1, nextNumber;
  
    printf("Fibonacci sequence: \n");

    for (int i = 0; i < n; i++) {
        if (i <= 1)
            nextNumber = i;
        else {
            nextNumber = firstNumber + secondNumber;
            firstNumber = secondNumber;
            secondNumber = nextNumber;
        }
        // Visualize the Fibonacci sequence by using asterisks
        for (int j = 0; j < nextNumber; j++)
            printf("*");

        printf("\n");
    }
}

int main() {
    int number;
    printf("Enter the number of terms: ");
    scanf("%d", &number);

    // Check if the input is valid
    if (number <= 0)
        printf("Invalid input!\n");
    else
        printFibonacci(number);

    return 0;
}