//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: beginner-friendly
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10
#define NUM_TESTS 3

int main() {
    const char* words[MAX_WORDS] = {"programming", "keyboard", "typing", "computer", "monitor", "mouse", "software", "hardware", "algorithm", "database"};
    char input[MAX_WORD_LENGTH];
    int total_time = 0;
    int num_words_correct = 0;
    int num_words_wrong = 0;

    srand(time(0)); // seed random number generator

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have to type %d words correctly as fast as you can.\n", MAX_WORDS);

    for (int i = 0; i < NUM_TESTS; i++) {
        // Randomly select words from the list
        int word_indices[MAX_WORDS];
        for (int j = 0; j < MAX_WORDS; j++) {
            word_indices[j] = rand() % MAX_WORDS;
        }

        // Display words and prompt for input
        printf("Test %d:\n", i + 1);
        for (int j = 0; j < MAX_WORDS; j++) {
            printf("%s ", words[word_indices[j]]);
        }
        printf("\n");
        printf("Type the words and hit enter:\n");

        // Record start time
        clock_t start_time = clock();

        // Get input
        fgets(input, MAX_WORD_LENGTH, stdin);

        // Record end time
        clock_t end_time = clock();
        total_time += end_time - start_time;

        // Check input against words
        char* token = strtok(input, " ");
        for (int j = 0; j < MAX_WORDS; j++) {
            if (token == NULL || strlen(token) != strlen(words[word_indices[j]]) || strcmp(token, words[word_indices[j]]) != 0) {
                num_words_wrong++;
            } else {
                num_words_correct++;
            }
            token = strtok(NULL, " ");
        }
    }

    // Calculate results
    double average_time = ((double)total_time) / (CLOCKS_PER_SEC * NUM_TESTS * MAX_WORDS);
    double wpm = ((double)num_words_correct) / (average_time / 60.0);
    double accuracy = 100 * ((double)num_words_correct) / ((double)(num_words_correct + num_words_wrong));
    printf("Results:\n");
    printf("Time: %.2f seconds\n", average_time);
    printf("WPM: %.2f\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}