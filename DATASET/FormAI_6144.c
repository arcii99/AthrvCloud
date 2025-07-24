//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: protected
/* 
   This is a unique C Typing Speed Test program designed to test the typing speed of the user.
   The user is presented with a series of random words and must type them as accurately and quickly 
   as possible. The program tracks the number of correct and incorrect words typed as well as the 
   typing speed in words per minute.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 20
#define TEST_TIME 60 // Test time in seconds

int main() {
    int correct = 0, incorrect = 0, i = 0, j = 0, word_count = 0;
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    char input[MAX_WORD_LENGTH];
    float elapsed_time = 0.0;
    time_t start_time, end_time;

    srand(time(NULL)); // Seed the random number generator

    printf("\nWelcome to the Typing Speed Test!\n");
    printf("\nYou will be presented with a series of random words which you must type as accurately and quickly as possible.\n");
    printf("\nYou have %d seconds to type as many words as you can.\n", TEST_TIME);
    printf("\nPress ENTER when you are ready to begin...\n");

    getchar(); // Wait for user to press ENTER

    start_time = time(NULL);

    // Generate random words
    for(i = 0; i < MAX_WORDS; i++) {
        for(j = 0; j < MAX_WORD_LENGTH; j++) {
            words[i][j] = (rand() % 26) + 'a';
        }
        words[i][j] = '\0';
    }

    // Present words to user and get input
    i = 0; // Reset counter
    while(elapsed_time < TEST_TIME) {
        printf("\n%s ", words[i]);
        scanf("%s", input);

        word_count++;

        if(strcmp(words[i], input) == 0) {
            correct++;
        }
        else {
            incorrect++;
        }

        i++;

        if(i == MAX_WORDS) {
            i = 0; // Reset counter
        }

        end_time = time(NULL);
        elapsed_time = difftime(end_time, start_time);
    }

    printf("\n\nTest complete!\n");
    printf("\nYou typed %d words correctly and %d words incorrectly.\n", correct, incorrect);
    printf("\nYour typing speed was %.2f words per minute.\n", (float)(word_count/elapsed_time)*60);

    return 0;
}