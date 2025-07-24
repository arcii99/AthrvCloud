//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initialize variables
    char typed_char;
    char random_char;
    int typing_speed = 0;
    int total_chars = 0;
    time_t start_time, end_time;

    // Seed random number generator
    srand(time(NULL));

    // Generate random characters and start timer
    printf("Type the following characters as fast as you can:\n\n");
    start_time = time(NULL);
    for(int i=0; i<50; i++) {
        random_char = (char) (rand() % 26 + 97);
        printf("%c", random_char);
    }
    printf("\n\n");

    // Prompt user to begin typing
    printf("Press any key to begin typing: ");
    getchar();

    // Get user input and calculate typing speed
    printf("\nType the characters exactly as you see them:\n\n");
    for(int i=0; i<50; i++) {
        typed_char = getchar();
        total_chars++;
        if(typed_char == random_char) {
            typing_speed++;
        }
    }

    // Stop timer and calculate elapsed time
    end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);

    // Calculate typing speed in characters per minute 
    double characters_per_minute = (double) total_chars / elapsed_time * 60;
    printf("\nTyping speed: %.2f characters per minute.\n", characters_per_minute);
    
    return 0;
}