//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 8
#define MAX_TIME 60

char words[][MAX_WORD_LENGTH + 1] = {
    "apple",
    "banana",
    "cherry",
    "date",
    "elderberry",
    "fig",
    "grape",
    "honeydew",
    "jackfruit",
    "kiwi",
    "lemon",
    "mango",
    "nectarine",
    "orange",
    "pear",
    "quince",
    "raspberry",
    "strawberry",
    "tangerine",
    "watermelon"
};

int total_words = sizeof(words) / sizeof(words[0]);

int main(void) {
    int correct_count = 0;
    int incorrect_count = 0;
    int typed_count = 0;
    int i;

    // Initialize random number generator
    srand(time(NULL));

    // Print welcome message
    printf("Welcome to the typing speed test! You have %d seconds to type as many words as possible.\n", MAX_TIME);

    // Loop until time runs out
    for (i = 0; i < MAX_TIME; i++) {
        int word_index = rand() % total_words;
        int time_remaining = MAX_TIME - i;
        char typed_word[MAX_WORD_LENGTH + 1];
        char *word = words[word_index];

        // Print new word
        printf("Type this word (%d seconds remaining): %s\n", time_remaining, word);

        // Get user input
        fgets(typed_word, MAX_WORD_LENGTH + 1, stdin);

        // Remove newline character from input
        typed_word[strcspn(typed_word, "\n")] = '\0';

        // Convert input to lowercase
        for (int j = 0; typed_word[j] != '\0'; j++) {
            typed_word[j] = tolower(typed_word[j]);
        }

        // Check if input matches word
        if (strcmp(typed_word, word) == 0) {
            correct_count++;
            printf("Correct!\n");
        } else {
            incorrect_count++;
            printf("Incorrect, the correct word was %s.\n", word);
        }

        // Keep track of number of words typed
        typed_count++;

        // If all words have been typed within the time limit, exit loop
        if (typed_count == total_words) {
            break;
        }
    }

    // Calculate typing speed and accuracy
    int typing_speed = (int)(((double)correct_count / (double)MAX_TIME) * 60.0);
    int accuracy = (int)(((double)correct_count / (double)typed_count) * 100.0);

    // Print final results
    printf("Time is up! You typed %d words with a typing speed of %d WPM and an accuracy of %d%%.\n", typed_count, typing_speed, accuracy);

    return 0;
}