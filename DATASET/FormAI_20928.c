//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printFibonacciSequence(int);

int main() {
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many numbers would you like to see? (Maximum: 15)\n");

    int userInput;
    scanf("%d", &userInput);

    if (userInput > 15) {
        printf("Sorry, the maximum number of Fibonacci Sequence numbers that can be displayed is 15.\n");
    } else {
        printf("Displaying the first %d numbers of the Fibonacci Sequence:\n", userInput);
        printFibonacciSequence(userInput);
    }

    printf("Thank you for using the Fibonacci Sequence Visualizer, come back soon!\n");

    return 0;
}

void printFibonacciSequence(int n) {
    int a = 0;
    int b = 1;
    int c;

    printf("%d, %d, ", a, b);

    for (int i = 2; i < n; i++) {
        c = a + b;
        printf("%d, ", c);
        a = b;
        b = c;

        // Pause for a moment to create a visual effect
        srand(time(NULL));
        int randomNum = rand() % 500 + 500;
        for (int j = 0; j < randomNum; j++) {
            // Just spinning wheels
        }
    }

    printf("\n");
}