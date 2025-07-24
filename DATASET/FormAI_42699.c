//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Romeo and Juliet
// Romeo and Juliet: A Fibonacci Tale

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    // Declarations
    int i, n, first = 0, second = 1, next, count, rows = 10;

    // Introduction
    printf("This Fibonacci sequence visualizer is a tale of two numbers, Romeo and Juliet.\n\n");

    printf("Romeo is the first number (0).\n");
    printf("Juliet is the second number (1).\n\n");

    printf("As they dance, add them together to find their next number. Continue this pattern to create the Fibonacci sequence.\n");

    printf("Now, let's watch Romeo and Juliet's dance!\n\n\n");

    // Delay function
    void delay(int number_of_seconds) {
        // Converting time into milli_seconds
        int milli_seconds = 1000 * number_of_seconds;

        // Stroing start time
        clock_t start_time = clock();

        // looping until required time is not achieved
        while (clock() < start_time + milli_seconds)
            ;
    }

    // For loop to generate sequence and visualize
    for (count = 0; count < rows; count++) {
        printf("\n");

        // Delay to visualize the movement of the numbers
        delay(500);

        // Print Romeo and Juliet's numbers
        printf("Romeo: %d\t", first);
        printf("Juliet: %d\t", second);

        // Loop to generate sequence
        for (i = 0; i < rows - count; i++) {
            if (i == 0 || i == 1) {
                // Skip Romeo and Juliet's numbers
                next = i;
            }
            else {
                // Add Romeo and Juliet to find next number in sequence
                next = first + second;
                // Update Romeo and Juliet's values
                first = second;
                second = next;
            }
            // Print generated number
            printf("%d\t", next);
        }
    }
    return 0;
}