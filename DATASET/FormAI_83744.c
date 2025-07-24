//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include<stdio.h>

int main(){

    // This is an Error Handling Example Program in C!
    // Let's get started by defining some variables
    int num1, num2, result;

    // First, we need to get some inputs from the user
    printf("Enter two numbers: ");
    if(scanf("%d %d", &num1, &num2) == 2){

        // Now that we have the user input, let's do some calculations!
        if(num2 != 0){

            result = num1 / num2;
            printf("%d / %d = %d\n", num1, num2, result);

        } else {

            // Uh oh! We can't divide by zero!
            printf("Error: Cannot divide by zero\n");

            // Let's exit the program with an error code
            return 1;
        }

    } else {

        // Whoops! It looks like the user didn't enter two numbers
        printf("Error: Expected two numbers, but only received one\n");

        // Let's exit the program with an error code
        return 1;
    }

    // Everything went smoothly! Let's end the program with a success code
    return 0;
}