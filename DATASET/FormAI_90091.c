//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: genious
#include <stdio.h>

void printFibonacci(int num);
// A function that prints the Fibonacci sequence up to the given number

int main() {
    int num;
    printf("Welcome to the Fibonacci Sequence Visualizer Program!\n\n");
    printf("Please enter the number of terms you want to display: ");
    scanf("%d", &num);
    printf("\n\n");

    printf("Visualizing Fibonacci sequence...\n\n");
    printFibonacci(num); // Calling the function to print the sequence
    return 0;
}

void printFibonacci(int num) {
    int a = 0, b = 1, c;
    for(int i=1; i<=num; i++) {
        printf("%d, ", a); // Printing the current number
        c = a + b;
        a = b; // Updating the current numbers
        b = c;
        if(i%5 == 0 || i==num) printf("\n"); // Adding line break after every 5 numbers or at the end
    }
    printf("\n\n");
    printf("Fibonacci sequence visualized successfully!");
}