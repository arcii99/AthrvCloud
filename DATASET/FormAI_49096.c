//FormAI DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    /* Ask the user to imagine a simple program. */
    printf("Imagine a simple program: ");

    /* Start the timer to measure the user's imagination speed. */
    clock_t begin = clock();

    /* Wait for the user to imagine the program. */
    while (getchar() != '\n');

    /* Stop the timer and calculate the elapsed time in seconds 
    (converted from clock ticks). */
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    /* Print the user's imagination speed. */
    printf("Your imagination speed is: %f seconds.\n", time_spent);

    return 0;
}