//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_STRING_LENGTH 50
#define TEST_TIME_LIMIT_SECS 60

int main() {
    char quote[MAX_STRING_LENGTH] = "The quick brown fox jumps over the lazy dog";
    int correct_chars = 0, total_chars = 0, word_count = 1, test_time = 60;
    time_t start_time, curr_time;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have 60 seconds to type the following quote:\n%s\n\n", quote);
    printf("Press ENTER when you're ready to start.\n");
    getchar();

    time(&start_time);
    while (test_time > 0) {
        char c = getchar();
        time(&curr_time);

        if (c == '\n') {
            word_count++;
        }
        else if (!isspace(c)) {
            total_chars++;

            if (c == quote[correct_chars]) {
                correct_chars++;
            }

            if (correct_chars == MAX_STRING_LENGTH - 1) {
                printf("Congratulations! You typed the quote correctly in %d seconds!\n", TEST_TIME_LIMIT_SECS - test_time);
                printf("Your typing speed is: %.2f words per minute\n", word_count / (double) (TEST_TIME_LIMIT_SECS - test_time) * 60.0);
                return 0;
            }
        }

        if (difftime(curr_time, start_time) >= 1.0) {
            test_time--;
            if (test_time > 0) {
                printf("\rYou have %d seconds remaining...", test_time);
            }
            fflush(stdout);
            start_time = curr_time;
        }
    }

    printf("\n\nTime's up! You typed %d out of %d characters correctly.\n", correct_chars, total_chars);
    printf("Your typing speed is: %.2f words per minute\n", word_count / (double) TEST_TIME_LIMIT_SECS * 60.0);

    return 0;
}