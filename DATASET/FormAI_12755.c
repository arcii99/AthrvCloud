//FormAI DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int calculate_recursive_factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }
    else if (num < 0) {
        printf("Error: Negative number entered.\n");
        exit(EXIT_FAILURE);
    }
    else {
        return num * calculate_recursive_factorial(num - 1);
    }
}

int main() {
    int num;
    printf("Enter a non-negative integer to compute the factorial of: ");
    scanf("%d", &num);

    int result = calculate_recursive_factorial(num);
    printf("The factorial of %d is %d\n", num, result);

    return 0;
}