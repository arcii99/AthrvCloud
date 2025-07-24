//FormAI DATASET v1.0 Category: Recursive ; Style: lively
#include <stdio.h>

// Let's create a function that will calculate the factorial of a given integer
int factorial(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int main(){

    int input;

    printf("Welcome to the Factorial Calculator! Please enter an integer: ");
    scanf("%d", &input);

    // Let's ensure that the user inputs a positive integer
    while(input < 0){
        printf("Oops! That's not a positive integer. Please try again: ");
        scanf("%d", &input);
    }

    // Now let's call our recursive function to calculate the factorial
    int result = factorial(input);
    printf("%d! = %d\n", input, result);

    printf("Thank you for using the Factorial Calculator!\n");

    return 0;
}