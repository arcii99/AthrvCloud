//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: excited
#include <stdio.h>

int main() {
    int num1 = 0;
    int num2 = 1;
    int temp;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n\n");

    printf("%d %d ", num1, num2);  // Printing the first two numbers of the sequence
    
    for (int i = 0; i < 48; i++) {  // Looping to print the next 48 numbers of the sequence
        temp = num1 + num2;
        printf("%d ", temp);
        num1 = num2;
        num2 = temp;
    }

    printf("\n\nAren't these numbers mesmerizing? They are the Fibonacci sequence!\n");
    printf("It's a sequence in which each number is the sum of the two preceding ones.\n");

    return 0;
}