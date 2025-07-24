//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_WORDS 50
#define MAX_LENGTH 15

char *words[MAX_WORDS] = { // word bank
    "keyboard", "monitor", "program", "computer", "language",
    "algorithm", "variable", "pointer", "syntax", "compiler",
    "debugger", "software", "hardware", "peripheral", "database",
    "interface", "server", "protocol", "internet", "network",
    "resolution", "processor", "battery", "graphics", "resolution",
    "multitasking", "operating", "system", "filesystem", "user",
    "interface", "prompt", "library", "window", "utility",
    "application", "memory", "distribution", "filesystem", "driver",
    "performance", "security", "encryption", "authentication", "command"
};

int main()
{
    srand(time(NULL)); // seed the random generator
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the word you see and press enter.\n");
    printf("You have 30 seconds to complete the test.\n");
    printf("Press enter to start the test.\n");
    getchar(); // wait for user to start test
    clock_t start_time = clock(); // start the timer
    int correct_words = 0, incorrect_words = 0, total_words = 0;
    while((clock() - start_time) / CLOCKS_PER_SEC <= 30) { // run for 30 seconds
        char word[MAX_LENGTH+1];
        strcpy(word, words[rand() % MAX_WORDS]); // get a random word from the bank
        printf("%s ", word); // print the word for the user
        char input[MAX_LENGTH+1];
        scanf("%s", input); // get user input
        total_words++; // increment the word counter
        if(strcmp(input, word) == 0) { // if the user input matches the word
            correct_words++; // increment the correct word counter
        } else {
            incorrect_words++; // otherwise increment the incorrect word counter
        }
    }
    printf("\n\nYou typed %d words in 30 seconds.\n", total_words);
    printf("You typed %d correctly and %d incorrectly.\n", correct_words, incorrect_words);
    printf("Your typing speed was %d words per minute.\n", (int)(correct_words / 30.0 * 60.0));
    return 0;
}