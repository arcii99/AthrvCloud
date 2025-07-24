//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog"; //text to type
    char input[100]; //input from user
    int mistakes = 0; //counter for mistakes
    int cpm, wpm; //characters per minute and words per minute
    int time_taken; //time taken to type
    time_t start, end; //for calculating time taken

    printf("Type the following text: \n%s\n", text);
    time(&start); //start timer

    fgets(input, 100, stdin); //get user input

    for (int i = 0; i < strlen(text); i++) {
        if (tolower(input[i]) != tolower(text[i])) { //if input is not same as text
            mistakes++; //increment mistake counter
        }
    }

    time(&end); //stop timer
    time_taken = (int) difftime(end, start); //calculate time taken
    cpm = (strlen(text) - mistakes) * (60 / time_taken); //calculate cpm
    wpm = cpm / 5; //calculate wpm assuming average word length of 5 characters

    printf("Time taken: %d seconds\n", time_taken);
    printf("Characters per minute: %d\n", cpm);
    printf("Words per minute: %d\n", wpm);

    return 0;
}