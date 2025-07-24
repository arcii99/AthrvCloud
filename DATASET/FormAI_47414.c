//FormAI DATASET v1.0 Category: Error handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

//Let's create a function that will be called in main
void divide(int a, int b) {
    if (b == 0) {
        //If the user is trying to divide by zero, we will throw an error
        //and stop the program from crashing.
        //We can use the exit() function to terminate the program
        printf("Error! Cannot divide by zero.\n");
        exit(0);
    } else {
        printf("Result: %d\n", a/b);
    }
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");

    //Let's try to scan in two numbers from the user
    if (scanf("%d%d", &num1, &num2) != 2) {
        //If the user inputs anything other than two numbers,
        //we will throw an error and stop the program from crashing.
        printf("Error! Invalid input. Please enter two numbers.\n");
        exit(0);
    }

    //Now let's call our divide function
    divide(num1, num2);

    return 0;
}