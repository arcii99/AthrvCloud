//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define SENTENCE "The quick brown fox jumps over the lazy dog."

int main() {
    printf("Welcome to the typing speed test!\n");
    printf("Type the following sentence as fast and accurately as possible:\n");

    printf("%s\n\n", SENTENCE);

    time_t start_time, end_time;
    int elapsed_time;

    char input[100];
    fgets(input, 100, stdin);

    time(&start_time);

    int i = 0, correct_characters = 0;
    while (SENTENCE[i] != '\0' && input[i] != '\0') {
        if (tolower(SENTENCE[i]) == tolower(input[i])) {
            correct_characters++;
        }
        i++;
    }

    time(&end_time);

    elapsed_time = (int) difftime(end_time, start_time);

    printf("\nYou typed: %s\n\n", input);

    if (correct_characters == sizeof(SENTENCE) - 1 && elapsed_time <= 10) {
        printf("Congratulations! You typed the sentence correctly in %d seconds.\n", elapsed_time);
    } else if (correct_characters == sizeof(SENTENCE) - 1) {
        printf("You typed the sentence correctly, but it took you %d seconds.\n", elapsed_time);
    } else {
        printf("Sorry, the sentence is not typed correctly. Please try again.\n");
    }

    return 0;
}