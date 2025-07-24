//FormAI DATASET v1.0 Category: Recursive ; Style: relaxed
/*
 * This is a program that uses recursion to calculate the nth Fibonacci number
 * in a relaxed and easy to understand way. 
 *
 * Author: Chatbot
 * Date: June 25, 2021
 */

#include <stdio.h>

int fibonacci(int n);

int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // If the user enters a negative number, prompt them to enter a positive integer
    while(n < 0){
        printf("Please enter a positive integer: ");
        scanf("%d", &n);
    }

    printf("The %dth Fibonacci number is %d\n", n, fibonacci(n));

    return 0;
}

int fibonacci(int n)
{
    /*
     * The Fibonacci sequence is a series of numbers in which each number is
     * the sum of the two preceding ones, usually starting with 0 and 1
     */
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}