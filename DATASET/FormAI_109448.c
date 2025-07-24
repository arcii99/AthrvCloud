//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

int main() {
    char input_string[MAX_STRING_LENGTH];
    char test_string[] = "This is a typing speed test. Can you keep up?";

    time_t start_time, end_time;
    double elapsed_time;

    int correct_count = 0;
    int total_count = 0;

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following sentence as quickly and accurately as possible:\n");
    printf("%s\n", test_string);

    time(&start_time);

    fgets(input_string, MAX_STRING_LENGTH, stdin);

    time(&end_time);

    elapsed_time = difftime(end_time, start_time);

    printf("\nElapsed time: %.2f seconds\n", elapsed_time);

    printf("\nYour input: \n%s", input_string);

    for (int i = 0; i < MAX_STRING_LENGTH; i++) {
        if (test_string[i] == input_string[i]) {
            correct_count++;
        }
        total_count++;
        if (test_string[i] == '\0') {
            break;
        }
    }

    double accuracy = ((double)correct_count / total_count) * 100;

    printf("\nAccuracy: %.2f%%\n", accuracy);

    if (elapsed_time <= 5.0) {
        printf("Great job! You're a typing wizard!\n");
    } else if (elapsed_time <= 10.0) {
        printf("Not bad, but keep practicing!\n");
    } else {
        printf("Looks like you need some more practice!\n");
    }

    return 0;
}