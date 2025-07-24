//FormAI DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <string.h>

void readInput(int *input);
void recursiveFactorial(int input, int *result);

int main() {
    int input, result;
    readInput(&input);
    recursiveFactorial(input, &result);
    printf("The factorial of %d is %d\n", input, result);
    return 0;
}

void readInput(int *input) {
    char buffer[256];
    printf("Input a positive integer: ");

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Error reading input.\n");
        readInput(input); // Recursive call
        return;
    }

    int num = sscanf(buffer, "%d", input);
    if (num != 1 || *input <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        readInput(input); // Recursive call
        return;
    }
}

void recursiveFactorial(int input, int *result) {
    if (input == 1) {
        *result = 1;
        return;
    } else if (input < 1) {
        printf("Error: input is less than 1.\n");
        return;
    }

    int temp;
    recursiveFactorial(input - 1, &temp);
    if (temp == 0) {
        printf("Error: result of previous calculation is 0.\n");
        return;
    }

    *result = input * temp;
}