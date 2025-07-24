//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

//function declaration
int factorial(int num);

int main() {
    int num;
    printf("Enter a positive integer to find its factorial: ");
    scanf("%d", &num);
    if (num >= 0) {
        int result = factorial(num);
        printf("The factorial of %d is %d", num, result);
    } else {
        printf("The number should be positive!");
    }
    return 0;
}


//Factorial function definition - recursive
int factorial(int num) {
    if (num <= 1) //base case
        return 1;
    else //recursive case
        return num * factorial(num - 1);
}