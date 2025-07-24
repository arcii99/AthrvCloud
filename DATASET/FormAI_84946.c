//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_WORD_LEN 20
#define TIME_LIMIT 60

int main() {
    srand(time(NULL)); // seed the random function with current time
    char words[MAX_WORDS][MAX_WORD_LEN]; // array to store randomly generated words
    int score = 0; // initialize score to 0
    time_t start_time, end_time; // variables to keep track of time
    double time_taken;

    // generate random words and store in array
    for(int i=0; i<MAX_WORDS; i++) {
        for(int j=0; j<MAX_WORD_LEN; j++) {
            char random_char = (rand() % 26) + 97; // generate random lowercase character
            words[i][j] = random_char;
        }
        words[i][MAX_WORD_LEN-1] = '\0'; // add null terminator at the end
    }

    printf("Welcome to the futuristic Typing Speed Test!\n");
    printf("You have %d seconds to type as many words as you can. Ready... go!\n\n", TIME_LIMIT);
    start_time = time(NULL); // get start time

    // loop to display words and take user input
    for(int i=0; i<MAX_WORDS; i++) {
        printf("%s: ", words[i]);
        char input[MAX_WORD_LEN];
        scanf("%s", input);
        if(strcmp(input, words[i]) == 0) { // if user input matches generated word
            score++;
        }
        end_time = time(NULL); // get current time
        time_taken = difftime(end_time, start_time); // calculate time taken
        if(time_taken >= TIME_LIMIT) { // exit loop if time limit exceeded
            break;
        }
    }

    printf("\nTime's up! You typed %d words in %.2lf seconds.\n", score, time_taken);
    return 0;
}