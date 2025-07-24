//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char sentence[] = "The quick brown fox jumps over the lazy dog."; // test sentence
    int len = sizeof(sentence) / sizeof(char); // length of the sentence
    int i, j, k, c, wpm, errors, total_chars_typed, time_taken;
    clock_t start_time, end_time; // for measuring time taken
    
    printf("\nWelcome to the Typing Speed Test!\n\nType the following sentence as fast as you can:\n\n%s\n\n", sentence);
    
    getchar(); // wait for user to press any key before starting the test
    
    srand(time(NULL)); // for generating random characters
    
    start_time = clock(); // start measuring time
    
    i = 0; // position of character in sentence
    total_chars_typed = errors = 0; // initialize variables
    
    while (i < len - 1) // loop until end of sentence
    {
        c = rand() % 93 + 33; // generate random character between ASCII 33-126
        
        if (c == sentence[i])
        {
            putchar(c); // print correct character
            i++; // move to next character in sentence
            total_chars_typed++; // increase count of characters typed
        }
        else
            errors++; // increase count of errors
        
        fflush(stdout); // flush output buffer
    }
    
    end_time = clock(); // stop measuring time
    
    time_taken = (int)(end_time - start_time) / CLOCKS_PER_SEC; // calculate time taken in seconds
    wpm = (int)(((float)total_chars_typed / 5) / ((float)time_taken / 60)); // calculate words per minute
    
    printf("\n\nTime taken: %d seconds", time_taken);
    printf("\nTotal characters typed: %d", total_chars_typed);
    printf("\nTotal errors made: %d", errors);
    printf("\nWords per minute: %d", wpm);
    
    return 0;
}