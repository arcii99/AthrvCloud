//FormAI DATASET v1.0 Category: Arithmetic ; Style: lively
/*Hey there!
  Welcome to my program that uses arithmetic operators.
  I am going to demonstrate how we can manipulate numbers with some creative code.
*/

#include <stdio.h>

int main()
{
    int n1, n2, sum, product, quotient, remainder, difference;
    double avg;
    
    //Let's start by asking the user for two numbers
    printf("Please enter two numbers: \n");
    scanf("%d %d", &n1, &n2);
    
    //Now let's do some arithmetic operations and print out the results in a fancy way
    
    sum = n1 + n2;
    printf("\nThe sum of %d and %d is %d", n1, n2, sum);
    
    difference = n1 - n2;
    printf("\nThe difference between %d and %d is %d", n1, n2, difference);
    
    product = n1 * n2;
    printf("\nThe product of %d and %d is %d", n1, n2, product);
    
    quotient = n1 / n2;
    printf("\nThe quotient of %d divided by %d is %d", n1, n2, quotient);
    
    remainder = n1 % n2;
    printf("\nThe remainder of %d divided by %d is %d", n1, n2, remainder);
    
    avg = (double)(n1 + n2) / 2;
    printf("\nThe average of %d and %d is %.2lf", n1, n2, avg);
    
    //That was fun! Let's end the program with some words of wisdom
    
    printf("\n\nRemember, arithmetic is the basic foundation of all math. Keep practicing and stay curious!\n\n");
    
    return 0;
}