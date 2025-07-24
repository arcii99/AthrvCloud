//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    char characters[] = "abcdefghijklmnopqrstuvwxyz"; // array of all lowercase alphabets
    srand(time(NULL)); // initialize random seed
    int count = 0; // variable to keep track of number of correct characters typed
    int mistakes = 0; // variable to keep track of number of mistakes made
    double time_taken = 0; // variable to keep track of time taken to complete typing test
    clock_t start_time, end_time; // variables to keep track of start and end time of typing test

    printf("Welcome to the Typing Speed Test.\n");
    printf("Type the following passage as fast and accurately as possible:");

    // paragraph to be typed
    printf("\n\nThe quick brown fox jumps over the lazy dog.\n");

    // loop until user types the entire paragraph correctly
    while (count < 43) {
        char c = characters[rand() % 26]; // randomly select a lowercase alphabet
        printf("\nType the letter ' %c ': ", c);
        start_time = clock(); // start timer
        char input = getchar(); // get user input
        end_time = clock(); // end timer

        if (input == c) { // check if user typed the correct character
            count++;
            time_taken += (double)(end_time - start_time) / CLOCKS_PER_SEC; // calculate time taken for correct input
        }
        else {
            mistakes++;
        }
    }

    printf("\n\nCongratulations, you have completed the typing test!\n");
    printf("You typed the paragraph correctly in %g seconds.\n", time_taken);
    printf("You made %d mistake(s).\n", mistakes);

    return 0;
}