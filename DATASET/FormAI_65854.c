//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int factorial(int num);

int main() {
    int number;
    printf("Welcome to the Factorial Calculator!\n");
    printf("Please enter a positive integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("\nSorry, Factorial of negative numbers is not defined!");
        return 0;
    }
    else {
        printf("\nYou entered %d\n", number);
        printf("The factorial of %d is %d.\n", number, factorial(number));
    }
    return 0;
}

int factorial(int num) {
    if (num == 0) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}