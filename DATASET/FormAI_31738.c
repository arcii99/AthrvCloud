//FormAI DATASET v1.0 Category: Benchmarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

    char phrase[30] = "Hello, World!"; // the phrase to be typed
    char input[30]; // the user's typed input
    int time_start, time_end, time_elapsed; // variables to record time
    int num_words = 2; // number of words in phrase
    double time_min; // time taken in minutes
    double speed; // typing speed in words per minute

    printf("Type the following phrase as fast as you can:\n%s\n\n", phrase);

    // record starting time
    time_start = clock();

    // get user input
    scanf("%[^\n]", input);

    // record ending time
    time_end = clock();

    // calculate time elapsed
    time_elapsed = time_end - time_start;

    // convert time elapsed to minutes
    time_min = (double)time_elapsed / CLOCKS_PER_SEC / 60;

    // calculate typing speed
    speed = (double)num_words / time_min;

    // output results
    printf("\nTime Elapsed: %d milliseconds\n", time_elapsed);
    printf("Typing Speed: %.2f words per minute\n", speed);

    return 0;
}