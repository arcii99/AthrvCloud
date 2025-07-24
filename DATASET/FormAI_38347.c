//FormAI DATASET v1.0 Category: Recursive ; Style: genious
#include<stdio.h>

int calculateFactorial(int num) {
    if (num == 1) {
        return 1;
    }
    else {
        return num * calculateFactorial(num - 1);
    }
}

int main() {
    printf("Welcome to the Factorial Calculator\n");
    printf("Please enter a number: ");
    int num;
    scanf("%d", &num);
    if (num < 0) {
        printf("Invalid input!\nThe number must be positive.\n");
    }
    else {
        int result = calculateFactorial(num);
        printf("The factorial of %d is %d\n", num, result);
    }
    return 0;
}