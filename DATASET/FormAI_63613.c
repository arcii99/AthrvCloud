//FormAI DATASET v1.0 Category: Benchmarking ; Style: happy
#include <stdio.h>
#include <time.h>

int main() {
    printf("Welcome to the Happy C Benchmarking program!\n");
    printf("We are going to measure how long it takes for this program to say the alphabet backwards.\n");
    
    // Start the timer
    clock_t start = clock();

    // Say the alphabet backwards
    char alphabet[27] = "zyxwvutsrqponmlkjihgfedcba";
    printf("%s\n", alphabet);

    // End the timer
    clock_t end = clock();

    // Calculate the elapsed time
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the elapsed time
    printf("It took %f seconds to say the alphabet backwards.\n", elapsed_time);

    printf("Now let's see how many times we can print \"Hello World\" in 1 second!\n");

    // Start the timer
    start = clock();

    // Print "Hello World" as many times as possible in 1 second
    int count = 0;
    while (((double)(clock() - start) / CLOCKS_PER_SEC) < 1.0) {
        count++;
        printf("Hello World\n");
    }

    // End the timer
    end = clock();

    // Calculate the number of times "Hello World" was printed
    int frequency = count / (int)elapsed_time;

    // Print the results
    printf("In 1 second, we printed \"Hello World\" %d times!\n", frequency);

    // Exit the program
    return 0;
}