//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_TIME 60

int main(void) {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int i = 0;
    int j = 0;
    int correct = 0;
    int incorrect = 0;
    time_t start_time, end_time;
    double time_difference;

    printf("*** C TYPING SPEED TEST ***\n");

    printf("Type the following sentence as fast as possible:\n\n");
    printf("The quick brown fox jumps over the lazy dog.\n\n");

    time(&start_time);

    while (i < MAX_TIME) {
        fgets(input, MAX_LENGTH, stdin);
        j = 0;
        while (input[j] != '\0') {
            if (input[j] == output[j]) {
                correct++;
            } else {
                incorrect++;
            }
            j++;
        }
        i++;
    }

    time(&end_time);
    time_difference = difftime(end_time, start_time);

    printf("\nNumber of correct characters: %d\n", correct);
    printf("Number of incorrect characters: %d\n", incorrect);
    printf("Time taken: %.2f seconds\n", time_difference);

    return 0;
}