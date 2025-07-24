//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_TIME 60

void generate_words(char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    // Define a list of possible characters
    char chars[] = "abcdefghijklmnopqrstuvwxyz";
    int num_chars = strlen(chars);

    // Generate random words
    for (int i = 0; i < MAX_WORDS; i++) {
        int word_length = rand() % MAX_WORD_LENGTH + 1;
        for (int j = 0; j < word_length; j++) {
            int char_index = rand() % num_chars;
            words[i][j] = chars[char_index];
        }
        words[i][word_length] = '\0';
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    char words[MAX_WORDS][MAX_WORD_LENGTH];
    generate_words(words);

    printf("Typing Speed Test\n\n");
    printf("Instructions: Type the words as quickly and accurately as possible.\n");
    printf("You have %d seconds to type as many words as you can.\n", MAX_TIME);
    printf("Press enter to start...\n");
    getchar(); // Wait for user to press enter

    int correct_words = 0;
    int total_words = 0;
    time_t start_time = time(NULL);
    time_t end_time = start_time + MAX_TIME;

    while (time(NULL) < end_time) {
        // Get a random word from the list
        int word_index = rand() % MAX_WORDS;
        char word[MAX_WORD_LENGTH];
        strcpy(word, words[word_index]);

        printf("%s ", word);
        char response[MAX_WORD_LENGTH];
        scanf("%s", response);

        if (strcmp(word, response) == 0) {
            printf("Correct!\n");
            correct_words++;
        } else {
            printf("Incorrect. Correct word: %s\n", word);
        }

        total_words++;
    }

    double elapsed_time = difftime(time(NULL), start_time);
    double typing_speed = (double)correct_words / elapsed_time * 60;
    printf("\nTime up! You typed %d words correctly out of %d.\n", correct_words, total_words);
    printf("Your typing speed was %.2f words per minute.\n", typing_speed);

    return 0;
}