//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: modular
#include <stdio.h>

// function to generate Fibonacci sequence
int fibonacci(int num) {
    if(num < 2)
        return num;
    else
        return (fibonacci(num-1) + fibonacci(num-2));
}

// function to print the Fibonacci sequence
void printFibonacci(int num) {
    int i;
    printf("The Fibonacci sequence up to %d is:\n", num);
    for (i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }   
}

// main function to run the program
int main(void) {
    int num;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &num);
    printFibonacci(num);
    return 0;
}