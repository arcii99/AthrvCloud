//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define NUM_WORDS 50
#define WORD_LENGTH 10

int main() {
    // Generate random list of words
    char words[NUM_WORDS][WORD_LENGTH];
    srand(time(NULL));
    for (int i = 0; i < NUM_WORDS; i++) {
        for (int j = 0; j < WORD_LENGTH - 1; j++) {
            words[i][j] = 'a' + rand() % 26;
        }
        words[i][WORD_LENGTH - 1] = '\0';
    }

    // Print out instructions and wait for user to start test
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given %d randomly generated words to type.\n", NUM_WORDS);
    printf("Type each word and hit enter to move on to the next word.\n");
    printf("When you are ready, press enter to begin.\n");
    getchar();

    // Start the timer and track accuracy and WPM
    time_t start_time = time(NULL);
    int num_correct = 0, num_words = 0;
    char input[WORD_LENGTH + 1];
    while (num_words < NUM_WORDS) {
        // Print out the current word and get user input
        printf("%s ", words[num_words]);
        scanf("%s", input);

        // Check if input matches the current word
        if (strcmp(input, words[num_words]) == 0) {
            num_correct++;
        }

        // Move to the next word
        num_words++;
    }

    // Calculate WPM and accuracy
    double elapsed_time = difftime(time(NULL), start_time);
    double wpm = (double)NUM_WORDS / (elapsed_time / 60.0);
    double accuracy = (double)num_correct / (double)NUM_WORDS * 100.0;

    // Print out results
    printf("Congratulations! You typed %d words in %.1lf seconds.\n", NUM_WORDS, elapsed_time);
    printf("Your typing speed is %.1lf WPM.\n", wpm);
    printf("Your accuracy is %.1lf%%.\n", accuracy);

    return 0;
}