//FormAI DATASET v1.0 Category: Recursive ; Style: lively
#include<stdio.h>

int recursive_factorial(int num){
    // Base case: If num is 0 or 1, return 1
    if (num == 0 || num == 1){
        return 1;
    }
    // Call the function recursively with num - 1
    int factorial = recursive_factorial(num - 1);
    // Multiply the factorial with num and return the result
    return factorial * num;
}

int main(){
    int number;
    printf("Welcome to the Factorial Calculator!\n");
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    // Check if the input is valid
    if (number < 0){
        printf("Invalid input! Please enter a positive integer.\n");
    }
    else{
        // Call the recursive function to calculate the factorial
        int result = recursive_factorial(number);
        printf("The factorial of %d is %d\n", number, result);
    }
    printf("Thanks for using the Factorial Calculator!\n");
    return 0;
}