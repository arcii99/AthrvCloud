//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Linus Torvalds
/**
 * Linus Torvalds-style C Typing Speed Test
 *
 * This program presents the user with a series of random phrases to type out, and records
 * their typing speed in words per minute (WPM). At the end of the test, the average WPM
 * is calculated and displayed.
 *
 * To run the test, simply compile and execute the program. The user will be prompted to
 * enter their name, and then the test will begin.
 *
 * Author: Linus Torvalds (parody by [Your Name Here])
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_PHRASES 10
#define PHRASE_LENGTH 50
#define MAX_NAME_LENGTH 50

/* An array of phrases to type out */
char phrases[NUM_PHRASES][PHRASE_LENGTH+1] = {
    "The quick brown fox jumps over the lazy dog",
    "She sells seashells by the seashore",
    "Peter Piper picked a peck of pickled peppers",
    "How much wood would a woodchuck chuck if a woodchuck could chuck wood",
    "I scream, you scream, we all scream for ice cream",
    "Red lorry, yellow lorry, red lorry, yellow lorry",
    "Sally sells sea shells by the sea shore",
    "Unique New York, Unique New York",
    "The seething sea ceaseth and thus the seething sea sufficeth us.",
    "I saw Susie sitting in a shoe shine shop." };

/**
 * Calculates the number of words in a given string.
 *
 * Parameters:
 *   str - the string to count words in
 *
 * Returns:
 *   the number of words in the string
 */
int count_words(const char *str) {
    int words = 0;
    int in_word = 0;
    while (*str) {
        if (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\f') {
            if (in_word) {
                in_word = 0;
                words++;
            }
        } else {
            in_word = 1;
        }
        str++;
    }
    if (in_word) {
        words++;
    }
    return words;
}

int main() {
    char name[MAX_NAME_LENGTH+1];
    int total_wpm = 0;
    int i;

    /* Seed the random number generator with the current time */
    srand(time(NULL));

    printf("Welcome to the Linus Torvalds-style C Typing Speed Test!\n");
    printf("Please enter your name: ");
    fgets(name, MAX_NAME_LENGTH+1, stdin);
    name[strcspn(name, "\n")] = '\0'; /* Remove trailing newline */

    printf("\nGet ready to type! You will be presented with %d phrases.\n", NUM_PHRASES);
    printf("Type each phrase and hit enter when you're done. Your typing speed will be calculated.\n\n");

    for (i = 0; i < NUM_PHRASES; i++) {
        char typed_phrase[PHRASE_LENGTH+1];
        int start_time, end_time, elapsed_time;
        int words, wpm;

        /* Present the next phrase to type */
        printf("Phrase %d: %s\n", i+1, phrases[i]);

        /* Get user input */
        fgets(typed_phrase, PHRASE_LENGTH+1, stdin);

        /* Calculate WPM */
        start_time = time(NULL);
        end_time = start_time;
        words = count_words(phrases[i]);
        wpm = 0;
        while (strncmp(phrases[i], typed_phrase, PHRASE_LENGTH) != 0) {
            printf("Incorrect! Try again:\n");
            fgets(typed_phrase, PHRASE_LENGTH+1, stdin);
        }
        end_time = time(NULL);
        elapsed_time = end_time - start_time;
        if (elapsed_time > 0) {
            wpm = (int)(((float)words / elapsed_time) * 60.0);
        }
        printf("You typed %d words in %d seconds, for a speed of %d WPM.\n\n", words, elapsed_time, wpm);
        total_wpm += wpm;
    }

    printf("Great job, %s! Your average typing speed was %d WPM.\n", name, total_wpm / NUM_PHRASES);

    return 0;
}