//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: excited
#include <stdio.h>

int main() {
    printf("Get ready to see the Fibonacci sequence in action!\n\n");

    // Getting input from the user
    int n;
    printf("Please enter the number of terms you want to see: ");
    scanf("%d", &n);

    // Error handling
    if (n < 1) {
        printf("Sorry, you must enter a positive integer greater than 0.\n");
        return 0;
    }

    printf("Perfect! Here's your Fibonacci sequence:\n");

    // Initializing variables
    int num1 = 0, num2 = 1, nextNum;

    // Looping through and printing the sequence
    for (int i = 1; i <= n; i++) {
        if (i == 1)
            printf("%d ", num1);
        else if (i == 2)
            printf("%d ", num2);
        else {
            nextNum = num1 + num2;
            num1 = num2;
            num2 = nextNum;

            printf("%d ", nextNum);
        }
    }

    printf("\n\nWOWZA! That was so fun to watch! Be ready to come back for more!\n");

    return 0;
}