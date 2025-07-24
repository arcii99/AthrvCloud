//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define SENTENCE "The quick brown fox jumps over the lazy dog"
#define SENTENCE_LEN 44

int main() {
    printf("Welcome to the Typing Speed Test!\n\n");

    // Set up input mode
    struct termios orig_attr, new_attr;
    tcgetattr(STDIN_FILENO, &orig_attr);
    new_attr = orig_attr;
    new_attr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);

    // Create sentence array
    char sentence[SENTENCE_LEN + 1];
    sprintf(sentence, "%s\n", SENTENCE);

    // Prompt user to start
    printf("Type the following sentence:\n%s", sentence);
    printf("Press any key to start...\n");
    getchar();

    // Start timer
    time_t start_time = time(NULL);

    // Track progress
    int index = 0, correct = 0, incorrect = 0;

    // Loop through sentence
    while (index < SENTENCE_LEN) {

        // Print current progress
        printf("\r%.*s", index, sentence);
        printf("\033[32;1m%c\033[0m%s", sentence[index], &sentence[index+1]);

        // Get user input
        char c = getchar();

        // Check for backspace
        if (c == 127) {
            if (index > 0) {
                index--;
            }
            continue;
        }

        // Ignore carriage return and newline
        if (c == 10 || c == 13) {
            continue;
        }

        // Check for end of sentence
        if (c == ' ' && index == SENTENCE_LEN - 1) {
            printf("\n\nCongratulations! You typed the sentence correctly!\n");
            printf("Time: %ld seconds\n", time(NULL) - start_time);
            printf("Correct keystrokes: %d\n", correct);
            printf("Incorrect keystrokes: %d\n", incorrect);
            break;
        }

        // Check for correct/incorrect input
        if (c == sentence[index]) {
            index++;
            correct++;
        } else {
            incorrect++;
        }
    }

    // Reset input mode
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_attr);

    return 0;
}