//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXIMUM_LENGTH 200
#define MAXIMUM_TIME_ALLOWED 10

int main(){
    int time_allowed = MAXIMUM_TIME_ALLOWED;
    char input_string[MAXIMUM_LENGTH];
    char original_string[MAXIMUM_LENGTH];
    int characters_typed = 0;
    int correct_characters = 0;
    int seconds_elapsed = 0;

    // Generate random string
    char *alphabet = "abcdefghijklmnopqrstuvwxyz";
    srand(time(NULL));
    for (int i = 0; i < MAXIMUM_LENGTH; i++){
        int random_index = rand() % 26;
        original_string[i] = alphabet[random_index];
    }
    printf("Welcome to the typing speed test!\n");
    printf("Type the following sentence as fast as possible:\n%s\n", original_string);

    // Start timer and receive input
    time_t start_time = time(NULL);
    while(seconds_elapsed <= time_allowed){
        fgets(input_string, MAXIMUM_LENGTH, stdin);
        characters_typed += strlen(input_string) - 1;
        if (strcmp(input_string, original_string) == 0){
            printf("Congratulations! You typed the sentence correctly.\n");
            break;
        }
        for (int i = 0; i < strlen(input_string) - 1; i++){
            if (input_string[i] == original_string[i]){
                correct_characters++;
            }
        }
        seconds_elapsed = (int) difftime(time(NULL), start_time);
    }

    // Calculate typing speed
    float accuracy = ((float) correct_characters / (float) characters_typed) * 100;
    float typing_speed = ((float) characters_typed / 5.0) / ((float) seconds_elapsed / 60.0);

    // Display results
    printf("\nResults:\n");
    printf("Total characters typed: %d\n", characters_typed);
    printf("Correct characters typed: %d\n", correct_characters);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Typing speed: %.2f words per minute\n", typing_speed);

    return 0;
}