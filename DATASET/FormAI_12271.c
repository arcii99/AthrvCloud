//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 10

void display_instructions() {
    printf("Welcome to the Happy Typing Speed Test!\n");
    printf("Here's how to play:\n");
    printf("- You will be presented with a list of words\n");
    printf("- Type each word as fast and accurately as you can\n");
    printf("- Your results will be displayed at the end\n");
    printf("\nGet ready to type some happy words!\n");
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {"sunshine", "butterfly", "happiness", "smile", "laugh", "friendship", "rainbow", "joy", "hope", "love", "happy", "cheerful", "funny", "positive", "light", "kindness", "grateful", "caring", "harmony", "sunnyday"};
    char user_input[MAX_WORD_LENGTH];
    int i, j, count = 0;
    double time_taken;
    clock_t start, end;

    // Shuffle the list of words
    srand(time(NULL));
    for (i = MAX_WORDS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }

    display_instructions();

    // Start the timer and display words
    start = clock();
    for (i = 0; i < MAX_WORDS; i++) {
        printf("Word #%d: %s\n", i + 1, words[i]);
        scanf("%s", user_input);
        // Convert user input to lowercase for comparison
        for (j = 0; j < strlen(user_input); j++) {
            user_input[j] = tolower(user_input[j]);
        }
        // Check if user input matches the word
        if (strcmp(user_input, words[i]) == 0) {
            count++;
        }
    }
    end = clock();

    // Calculate and display the results
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nCongratulations! You completed the Happy Typing Speed Test in %.2fs!\n", time_taken);
    printf("You typed %d out of %d words correctly\n", count, MAX_WORDS);
    printf("Your accuracy rate is %.2f%%\n", ((double)count / MAX_WORDS) * 100);

    return 0;
}