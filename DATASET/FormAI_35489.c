//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(void) {
    char input;
    int count = 0, num_chars = 0, num_words = 0, time_taken, wpm;
    time_t start_time, end_time;
    const int test_time = 60; // in seconds

    printf("\nType this sentence and press ENTER to begin the typing speed test:\n\n");
    printf("The quick brown fox jumps over the lazy dog.\n\n");

    while ((input = getchar()) != '\n' && input != EOF) {
        num_chars++;
        if (isspace(input)) {
            num_words++;
        }
    }

    printf("You will now have %d seconds to type the sentence as many times as possible.\n", test_time);
    printf("Type 'done' when you are finished.\n\n");

    time(&start_time); // start timer

    while ((time_taken = (int) difftime(time(NULL), start_time)) < test_time) {
        printf("Type the sentence:\n\n");
        printf("The quick brown fox jumps over the lazy dog.\n\n");

        while ((input = getchar()) != '\n' && input != EOF) {
            if (input == 'd' && getchar() == 'o' && getchar() == 'n' && getchar() == 'e') {
                goto done;
            }
            count++;
        }
    }

    done:
        time(&end_time); // stop timer

        printf("\nYou typed %d characters in %d seconds.\n", count, (int) difftime(end_time, start_time));
    
        wpm = (int) ((float) num_words / ((float) test_time / 60.0));
        printf("\nYour typing speed is: %d words per minute.\n", wpm);
        
        return 0;
}