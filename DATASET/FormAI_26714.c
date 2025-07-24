//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate random words for typing test
void generate_words(char *words[], int n) {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < n; i++) {
        int len = rand() % 9 + 1;
        words[i] = (char *) malloc(sizeof(char) * (len + 1));
        for (int j = 0; j < len; j++) {
            words[i][j] = letters[rand() % 26];
        }
        words[i][len] = '\0';
    }
}

int main() {
    srand(time(0));

    // Set the number of words and time for the test
    int num_words = 50;
    int time_limit = 60; // in seconds

    // Generate random words
    char *words[num_words];
    generate_words(words, num_words);

    // Print instructions
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have %d seconds to type as many words as you can.\n", time_limit);
    printf("Press enter to start the test.\n");
    getchar();

    // Start the timer and the test
    time_t start_time = time(0);
    int num_typed = 0;
    while (difftime(time(0), start_time) < time_limit) {
        printf("Type the following word: %s\n", words[num_typed]);
        char input[10];
        scanf("%s", input);
        if (strcmp(input, words[num_typed]) == 0) {
            printf("Correct!\n");
            num_typed++;
        } else {
            printf("Incorrect. Try again.\n");
        }
    }

    // Calculate results
    int num_correct = num_typed;
    int num_incorrect = num_words - num_typed;
    int score = (int) ((float) num_correct / num_words * 100);

    // Print results
    printf("Time's up!\n");
    printf("You typed %d words correctly.\n", num_correct);
    printf("You made %d mistakes.\n", num_incorrect);
    printf("Your typing speed is %d WPM.\n", score);

    // Free memory
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return 0;
}