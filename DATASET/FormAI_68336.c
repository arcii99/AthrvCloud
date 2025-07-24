//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 5
#define MAX_WORD_LEN 10

char words[MAX_WORDS][MAX_WORD_LEN] = {"typing", "speed", "test", "programming", "algorithm"};

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    printf("Welcome to the Typing Speed Test\n");
    printf("--------------------------------\n");
    printf("Type the word you see on the screen and hit enter to continue\n");
    printf("Press Ctrl-C to exit at any time\n\n");

    while(1) {
        // Choose a random word to display
        int word_index = rand() % MAX_WORDS;
        char word[MAX_WORD_LEN];
        strcpy(word, words[word_index]);

        printf("%s\n", word); // Display the chosen word

        // Get user input and measure typing speed
        clock_t start_time = clock();
        char input[MAX_WORD_LEN];
        fgets(input, MAX_WORD_LEN, stdin);
        clock_t end_time = clock();

        // Calculate typing speed in WPM (words per minute)
        double typing_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Calculate time taken to type, in seconds
        double typing_speed = 60 / typing_time; // Calculate typing speed in WPM
        
        printf("Your typing speed: %.2f WPM\n\n", typing_speed); // Display the typing speed
    }

    return 0;
}