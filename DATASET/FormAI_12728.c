//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Claude Shannon
#include <stdio.h>

//Function to generate fibonacci sequence to a specified limit
int fibonacci(int limit) {
    int firstNum = 0, secondNum = 1, nextNum = 0;

    printf("%d %d ", firstNum, secondNum);

    for(int i = 2; i < limit; i++) {
        nextNum = firstNum + secondNum;
        firstNum = secondNum;
        secondNum = nextNum;
        printf("%d ", nextNum);
    }

    return 0;
}

//Function to generate fibonacci sequence up to a specified element
void fibonacciRecursive(int limit, int* sequence, int index) {
    if(index >= limit) {
        return;
    }
    if(index == 0) {
        sequence[index] = index;
    }
    else if(index == 1) {
        sequence[index] = 1;
    }
    else {
        sequence[index] = sequence[index - 1] + sequence[index - 2];
    }

    printf("%d ", sequence[index]);
    fibonacciRecursive(limit, sequence, index + 1);
}

//Function to print fibonacci sequence as an animated visualizer
void visualizeFibonacci(int limit) {
    int sequence[limit];

    printf("Generating fibonacci sequence up to %d\n", limit);
    fibonacciRecursive(limit, sequence, 0);

    printf("\n\n");

    //Code for the visualizer
    printf("Visualizing fibonacci sequence\n");

    //Loop through the generated sequence and print the digits as ascending rows of stars
    for(int i = 0; i < limit; i++) {
        printf("%d: ", i + 1);
        for(int j = 0; j < sequence[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

//Main method to call the fibonacci and visualize functions
int main() {
    //Generate fibonacci sequence up to limit
    fibonacci(25);

    //Visualize sequence up to limit
    visualizeFibonacci(15);

    return 0;
}