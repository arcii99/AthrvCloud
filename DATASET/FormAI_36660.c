//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SENTENCE_SIZE 256
#define MAX_TIME 10 // seconds

int main() {
    char sentence[SENTENCE_SIZE] = "The quick brown fox jumps over the lazy dog.";
    int sentence_len = strlen(sentence); 
    char input[SENTENCE_SIZE];
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following sentence as fast as you can:\n\"%s\"\n", sentence);
    
    time_t start_time = time(NULL);
    int elapsed_time = 0;
    int correct_characters = 0;

    while (elapsed_time < MAX_TIME) {
        fgets(input, SENTENCE_SIZE, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character
        
        if (strcmp(input, sentence) == 0) { // Input matches sentence
            printf("You typed the sentence correctly! Congrats!\n");
            break;
        }
  
        int input_len = strlen(input);
        int i;
        for (i = 0; i < input_len && i < sentence_len; i++) { // Loop through characters
            if (input[i] != sentence[i]) {
                printf("Incorrect character at position %d. Expected '%c', but got '%c'.\n",
                       i+1, sentence[i], input[i]);
                break;
            } else {
                correct_characters++;
            }
        }
        
        // Print out current progress
        printf("You have typed %d correct characters out of %d. Keep it up!\n",
               correct_characters, sentence_len);
        
        elapsed_time = (int) difftime(time(NULL), start_time);
    }
    
    int total_time = (elapsed_time < MAX_TIME) ? elapsed_time : MAX_TIME;
    double typing_speed = ((double) correct_characters / total_time) * 60;
    printf("Typing speed: %.2f characters per minute\n", typing_speed);
    
    return 0;
}