//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_SIZE 100

int main() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following sentence as fast as you can:\n");

    char sentence[MAX_STRING_SIZE];
    strcpy(sentence, "The quick brown fox jumps over the lazy dog");

    time_t start_time = time(NULL);

    char user_input[MAX_STRING_SIZE];
    fgets(user_input, MAX_STRING_SIZE, stdin);

    time_t end_time = time(NULL);

    double time_taken = difftime(end_time, start_time);
    int accuracy = 0;
    
    if (strcmp(sentence, user_input) == 0) {
        accuracy = 100;
    }
    else {
        int i = 0;
        while (sentence[i] != '\0' && user_input[i] != '\0') {
            if (sentence[i] == user_input[i]) {
                accuracy++;
            }
            i++;
        }
        accuracy = (accuracy / strlen(sentence)) * 100;
    }

    printf("Time taken: %lf seconds\n", time_taken);
    printf("Accuracy: %d%%\n", accuracy);

    return 0;
}