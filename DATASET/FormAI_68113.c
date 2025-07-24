//FormAI DATASET v1.0 Category: Error handling ; Style: enthusiastic
#include <stdio.h>

int main() {
    int num1, num2, result;
    printf("Welcome to the Error Handling example program!\n");
    printf("Please enter two numbers to divide: ");
    if(scanf("%d %d", &num1, &num2) != 2) {
        printf("Error: Invalid input. Please enter two numbers separated by a space.\n");
        return 1;
    }
    if(num2 == 0) {
        printf("Error: You cannot divide by zero.\n");
        return 1;
    }
    result = num1 / num2;
    printf("%d divided by %d is equal to %d.\n", num1, num2, result);
    printf("Thank you for using this Error Handling example program!\n");
    return 0;
}