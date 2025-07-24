//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {
    char prompt[] = "The quick brown fox jumps over the lazy dog.";
    char user_input[MAX_STRING_LENGTH];
    int correct_count = 0, total_count = 0;
    clock_t start_time, end_time;

    printf("\n\n*** TYPING SPEED TEST ***\n\n");
    printf("Type the following sentence (without the quotes):\n\n%s\n\n", prompt);
    printf("Press Enter when finished.\n\n");

    // Start the timer after the user presses Enter
    while(getchar() != '\n');
    printf("READY...\n");
    getchar(); // Wait for user input
    start_time = clock();

    printf("\n\nGO!\n\n");

    // Get input from user and compare to prompt until Enter is pressed
    while(fgets(user_input, MAX_STRING_LENGTH, stdin)) {
        if(user_input[0] == '\n') {
            break;
        }
        for(int i = 0; i < strlen(user_input); i++) {
            if(tolower(prompt[i]) == tolower(user_input[i])) {
                correct_count++;
            }
            total_count++;
        }
    }

    // Calculate typing speed and output results
    end_time = clock();
    double typing_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    double words_per_min = (double) total_count * 60 / (5 * typing_time);
    printf("\n\nYour typing speed: %.2f words per minute!\n\n", words_per_min);

    return 0;
}