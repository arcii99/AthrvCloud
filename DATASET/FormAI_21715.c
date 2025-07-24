//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 15
#define MAX_WORD_LENGTH 10

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH] = { // List of words to type
        "hello", "world", "program", "typing", "speed",
        "test", "example", "innovative", "style", "creative",
        "compile", "run", "errors", "snippet", "starts"
    };

    srand(time(NULL)); // Randomize seed
    char input[MAX_WORD_LENGTH+1]; // Input buffer
    int i, total_chars = 0, correct_chars = 0, total_words = 0, correct_words = 0;
    printf("Type the following words as fast and accurately as possible:\n");

    for (i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i]); // Print the word
        total_chars += strlen(words[i]); // Count total characters
        total_words++;

        time_t start_time = time(NULL); // Start the timer
        scanf("%s", input); // Wait for input
        time_t end_time = time(NULL); // Stop the timer

        if (strcmp(input, words[i]) == 0) { // Compare input with word
            correct_chars += strlen(words[i]); // Count correct characters
            correct_words++;
        }

        printf("\nTime taken: %d seconds\n\n", (int)(end_time - start_time)); // Display time taken
    }

    printf("Result: %d/%d words and %d/%d characters were correct.\n",
           correct_words, total_words, correct_chars, total_chars); // Display results

    return 0;
}