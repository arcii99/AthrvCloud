//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 5
#define MAX_LEN 20

// function to generate random words
void generate_words(char words[MAX_WORDS][MAX_LEN]) {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    int i, j;

    for (i = 0; i < MAX_WORDS; i++) {
        for (j = 0; j < MAX_LEN-1; j++) {
            words[i][j] = letters[rand() % 26];
        }
        words[i][j] = '\0';
    }
}

int main() {
    char words[MAX_WORDS][MAX_LEN];
    int i, j, len, total_chars = 0, correct_chars = 0;
    clock_t start, end;
    double time_taken;

    // generate random words
    generate_words(words);

    // display instructions and countdown to start
    printf("Welcome to the Typing Test program!\n");
    printf("You will be given %d random words to type.\n", MAX_WORDS);
    printf("Once you start typing, the clock will start ticking.\n");
    printf("Get ready to begin in 3... 2... 1... GO!\n");

    // countdown to start
    for (i = 3; i >= 1; i--) {
        printf("%d...\n", i);
        sleep(1);
    }
    printf("GO!\n");

    // start clock
    start = clock();

    // loop through each word
    for (i = 0; i < MAX_WORDS; i++) {
        // display current word
        printf("%d. %s ", i+1, words[i]);

        // get user input
        char input[MAX_LEN];
        fgets(input, MAX_LEN, stdin);

        // remove newline character from input
        len = strlen(input);
        if (input[len-1] == '\n') {
            input[len-1] = '\0';
        }

        // compare input to correct word
        for (j = 0; j < strlen(words[i]); j++) {
            if (input[j] == words[i][j]) {
                correct_chars++;
            }
            total_chars++;
        }

        // display result for current word
        printf("You typed: %s\n", input);
        printf("Accuracy: %.2f%%\n", (double)correct_chars/total_chars*100);

        // reset counters for next word
        total_chars = 0;
        correct_chars = 0;
    }

    // end clock
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // display final results
    printf("Congratulations! You completed the typing test in %.2f seconds.\n", time_taken);
    printf("Your average typing speed: %.2f characters per second.\n", (double)total_chars/time_taken);

    return 0;
}