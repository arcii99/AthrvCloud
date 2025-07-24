//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // setting the seed for random numbers
    
    char phrase[] = "The quick brown fox jumps over the lazy dog"; // the phrase to type
    int phrase_length = sizeof(phrase)/sizeof(phrase[0]) - 1; // calculate length of phrase
    
    printf("Type the following phrase as fast as you can:\n%s\n", phrase);
    
    int i, correct_characters = 0;
    clock_t start, end;
    double time_taken; 
    
    char user_input[100]; // buffer for user input
    fgets(user_input, 100, stdin); // get user input
    
    start = clock(); // start timer
    
    for (i = 0; i < phrase_length; i++) {
        char random_char = (char)(rand() % 26 + 97); // generate random letters
        printf("%c", random_char); // print the random letter
        
        if (user_input[i] == phrase[i]) { // check if user input matches phrase
            correct_characters++;
        }
    }
    
    end = clock(); // end timer
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // calculate time taken in seconds
    
    int wpm = correct_characters / (time_taken / 60) / 5; // calculate words per minute
    
    printf("\nYou typed %d words.\n", correct_characters/5);
    printf("Your typing speed is %d WPM.\n", wpm);
    
    return 0; // end program
}