//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Function to generate the Fibonacci sequence
void generateFibonacci(int length) {
    int a = 0, b = 1, c, i;
    for (i = 0; i < length; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    printf("Welcome to the Fibonacci Sequence Visualizer!\n\n");

    int length;
    printf("Please enter the number of terms you would like to see in the sequence: ");
    scanf("%d", &length);

    printf("\n");
    generateFibonacci(length);

    printf("\n\nThank you for using the Fibonacci Sequence Visualizer!");

    return 0;
}