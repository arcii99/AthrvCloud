//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: single-threaded
#include <stdio.h>

void printFibonacci(int num) {
    int first = 0, second = 1, next, i; //initialize variables
    printf("%d %d ", first, second); //print first two numbers
    for (i = 2; i < num; i++) {
        next = first + second; // calculate the next number in sequence
        printf("%d ", next); //print it
        first = second; //update values
        second = next; //update values
    }
    printf("\n"); //print newline character
}

int main() {
    int num;
    printf("Enter the number of terms: ");
    scanf("%d", &num); //get user input for number of terms
    printf("Fibonacci Sequence for %d terms: \n", num);
    printFibonacci(num); //call function to print fibonacci sequence
    return 0;
}