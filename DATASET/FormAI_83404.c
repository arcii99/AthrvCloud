//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10    // Maximum number of words for the test
#define WORD_LEN 10     // Maximum length of each word

int main() {
    char words[MAX_WORDS][WORD_LEN];    // Array to store the words
    char input[WORD_LEN];               // Buffer to store user input
    int num_words, i, correct, mistakes;
    double time_taken;

    // Fill the words array with random words
    srand((unsigned int) time(NULL));
    for (i = 0; i < MAX_WORDS; i++) {
        for (int j = 0; j < WORD_LEN; j++) {
            words[i][j] = 'a' + rand() % 26;
        }
        words[i][WORD_LEN-1] = '\0';
    }

    // Print the words and ask the user to type them
    num_words = rand() % MAX_WORDS + 1;  // Pick a random number of words to show
    printf("Type the following %d words:\n", num_words);
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    // Get user input and check correctness
    time_t start_time = time(NULL);
    correct = mistakes = 0;
    for (i = 0; i < num_words; i++) {
        scanf("%s", input);
        if (strcmp(words[i], input) != 0) {
            mistakes++;
        } else {
            correct++;
        }
    }
    time_taken = difftime(time(NULL), start_time);

    // Calculate and display results
    printf("\nResults:\n");
    printf("Total words: %d\n", num_words);
    printf("Correct: %d\n", correct);
    printf("Mistakes: %d\n", mistakes);
    printf("Accuracy: %.2f%%\n", (double) correct / num_words * 100);
    printf("Time taken: %.2fs\n", time_taken);
    printf("Typing speed: %.2f words per minute\n", num_words / (time_taken / 60));

    return 0;
}