//FormAI DATASET v1.0 Category: Arithmetic ; Style: irregular
#include <stdio.h>

int main() {

// Let's create our variables:

int a = 12, b = 5, sum, subtract, multiply, divide;

// Now let's perform some operations with our variables:

sum = a + b;
subtract = a - b;
multiply = a * b;
divide = a / b;

// Now let's print the results!

printf("The sum of %d and %d is: %d\n", a, b, sum);
printf("The difference between %d and %d is: %d\n", a, b, subtract);
printf("The product of %d and %d is: %d\n", a, b, multiply);
printf("The quotient (%d/%d) is: %d\n", a, b, divide);
printf("But wait, there's more!\n");

// Let's add some interactive elements to our program:

printf("Enter a value for a: ");
scanf("%d", &a);

printf("Enter a value for b: ");
scanf("%d", &b);

sum = a + b;
subtract = a - b;
multiply = a * b;
divide = a / b;

printf("The sum of %d and %d is: %d\n", a, b, sum);
printf("The difference between %d and %d is: %d\n", a, b, subtract);
printf("The product of %d and %d is: %d\n", a, b, multiply);
printf("The quotient (%d/%d) is: %d\n", a, b, divide);
printf("Thanks for using our program! Have a great day :)\n");

// End of program

return 0;

}