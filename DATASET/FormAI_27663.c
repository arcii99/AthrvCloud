//FormAI DATASET v1.0 Category: Math exercise ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* This unique C Math exercise example program will
   calculate the factorial of a given number using
   both a recursive and iterative approach */

int factorial_iterative(int num) {
    int fact = 1, i;
    for(i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int factorial_recursive(int num) {
    if(num == 0 || num == 1)
        return 1;
    else
        return num * factorial_recursive(num-1);
}

int main() {
    int num;
    printf("Welcome to the Factorial Calculator!\n");
    printf("Please enter a positive integer: ");
    scanf("%d", &num);

    if(num < 0) {
        printf("Error! Factorial of a negative number doesn't exist.\n");
        printf("Please enter a positive integer: ");
        scanf("%d", &num);
    }

    printf("Calculating...\n");
    printf("Iterative approach: %d! = %d\n", num, factorial_iterative(num));
    printf("Recursive approach: %d! = %d\n", num, factorial_recursive(num));

    printf("Thank you for using the Factorial Calculator!\n");

    return 0;
}