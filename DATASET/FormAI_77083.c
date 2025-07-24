//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int word_count = 0;

void shuffle_words() {
    srand(time(NULL));
    for (int i = 0; i < word_count; i++) {
        int j = rand() % word_count;
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }
}

int main() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following words as fast as you can:\n");

    strcpy(words[word_count++], "computer");
    strcpy(words[word_count++], "keyboard");
    strcpy(words[word_count++], "program");
    strcpy(words[word_count++], "algorithm");
    strcpy(words[word_count++], "compile");
    strcpy(words[word_count++], "execute");
    strcpy(words[word_count++], "code");
    strcpy(words[word_count++], "syntax");
    strcpy(words[word_count++], "variable");
    strcpy(words[word_count++], "function");

    shuffle_words();

    int correct_words = 0;
    clock_t start_time = clock();

    for (int i = 0; i < word_count; i++) {
        printf("%s ", words[i]);
        char guess[MAX_WORD_LENGTH];
        scanf("%s", guess);
        if (strcmp(guess, words[i]) == 0) {
            correct_words++;
        }
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    int typing_speed = (int)((double)correct_words / elapsed_time * 60);

    printf("\n\nYou typed %d correct words in %.2f seconds.\n", correct_words, elapsed_time);
    printf("Your typing speed is %d words per minute!\n", typing_speed);

    return 0;
}