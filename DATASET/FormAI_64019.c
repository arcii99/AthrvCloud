//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_LENGTH 30

char words[MAX_WORDS][MAX_LENGTH] = {"paranoid", "hacker", "cybersecurity", "encryption", "password", "surveillance", "anonymity", "sensitive", "scramble", "suspicious"};
int num_words = sizeof(words) / sizeof(words[0]);

int main() {
    srand(time(NULL));
    int score = 0;
    time_t start_time, end_time;
    double elapsed_time;
    char input[MAX_LENGTH];
    int word_index, i;

    printf("Welcome to the Paranoid Typing Speed Test!\n\n");
    printf("You will be given 10 random words to type. Get ready!\n\n");
    printf("Press Enter to begin.");
    getchar();

    for (i = 0; i < MAX_WORDS; i++) {
        word_index = rand() % num_words;
        printf("Type the word: %s\n", words[word_index]);
        start_time = time(NULL);
        fgets(input, MAX_LENGTH, stdin);
        end_time = time(NULL);

        if (strcmp(input, words[word_index]) == 0) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect. The word was: %s\n", words[word_index]);
        }

        elapsed_time = difftime(end_time, start_time);
        printf("Time elapsed: %.2f seconds.\n\n", elapsed_time);
    }

    printf("Your final score is: %d\n", score);
    printf("Congratulations! You are officially paranoid.\n");

    return 0;
}