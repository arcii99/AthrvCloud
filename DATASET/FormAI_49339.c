//FormAI DATASET v1.0 Category: Error handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[100];

void check_input(int result) {
    if(result == 0) {
        char *error_message = "Invalid input! Please enter a valid positive integer.";
        perror(error_message);
        exit(EXIT_FAILURE);
    }
}

int calculate_factorial(int num) {
    int factorial = 1;
    for(int i = 1; i <= num; i++) {
        factorial *= i;
    }
    return factorial;
}

int main() {
    printf("Enter a positive integer to calculate its factorial: ");
    fgets(input, sizeof(input), stdin);

    int num = atoi(input);
    check_input(num);

    int factorial = calculate_factorial(num);
    printf("The factorial of %d is: %d\n", num, factorial);

    return 0;
}