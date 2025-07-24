//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: happy
#include <stdio.h>

// Function to print a happy message
void printHappyMsg() {
    printf("Yay! Let's generate Fibonacci sequence with a smile :)\n");
}

// Function to determine the nth Fibonacci number 
int fibonacci(int n) {
    if (n <= 2) {
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int numTerms;
    printHappyMsg();

    printf("How many terms of the sequence would you like to see?\n");
    scanf("%d", &numTerms);

    printf("\nHere is your Fibonacci sequence, enjoy!\n");

    // loop through the sequence and print each term
    for(int i = 1; i <= numTerms; i++) {
        int term = fibonacci(i);
        printf("%d", term);

        // add some visual flair to even-numbered terms
        if(term % 2 == 0) {
            printf(" :)");
        }

        printf(" ");
    }

    printf("\nHope you enjoyed our happy Fibonacci sequence! :D");

    return 0;
}