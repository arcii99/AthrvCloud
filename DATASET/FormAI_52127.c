//FormAI DATASET v1.0 Category: Educational ; Style: happy
#include <stdio.h>

int main() {
    // Greeting the user
    printf("Hello there! Let's learn some C programming today!\n");
    
    // Declaring variables
    int number1, number2, sum, product;
    
    // Prompting user to enter first number
    printf("Please enter the first number: ");
    scanf("%d", &number1);
    
    // Prompting user to enter second number
    printf("Please enter the second number: ");
    scanf("%d", &number2);
    
    // Calculating sum and product of the two numbers
    sum = number1 + number2;
    product = number1 * number2;
    
    // Displaying the results to the user
    printf("The sum of %d and %d is %d.\n", number1, number2, sum);
    printf("The product of %d and %d is %d.\n", number1, number2, product);
    
    // Closing message
    printf("Congratulations, you have just learned how to add and multiply numbers in C programming!\n");
    
    return 0;
}