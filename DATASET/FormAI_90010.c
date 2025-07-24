//FormAI DATASET v1.0 Category: Educational ; Style: unmistakable
#include <stdio.h>

// Define the maximum length of the name
#define MAX_NAME_LENGTH 20 

int main() {
    char name[MAX_NAME_LENGTH];

    // Ask for user's name
    printf("Please enter your name: ");
    scanf("%s", name);

    // Print a customized welcome message
    printf("Hello, %s!\n", name);
    printf("Welcome to our C Programming course.\n");
    printf("To start, let's learn how to create a function.\n");

    // Define a simple function that returns the square of a number
    int square(int num) {
        return num * num;
    }

    // Test the function with some inputs
    int a = 5;
    int b = 10;
    printf("The square of %d is %d.\n", a, square(a));
    printf("The square of %d is %d.\n", b, square(b));

    // Ask the user for two numbers to add
    int num1, num2;
    printf("Please enter two numbers to add: ");
    scanf("%d %d", &num1, &num2);

    // Define a function to add two numbers and return the result
    int add(int x, int y) {
        return x + y;
    }

    // Call the add function with user inputs
    int sum = add(num1, num2);
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);

    // Explain the use of if-else statements in C
    printf("Now, let's learn about if-else statements.\n");
    printf("These can be used to form conditional statements.\n");
    printf("For example, let's check if %d is greater than %d.\n", num1, num2);
    if (num1 > num2) {
        printf("%d is greater than %d.\n", num1, num2);
    } else {
        printf("%d is not greater than %d.\n", num1, num2);
    }

    // End the program with a goodbye message
    printf("That's it for now! Goodbye, %s.\n", name);

    return 0;
}