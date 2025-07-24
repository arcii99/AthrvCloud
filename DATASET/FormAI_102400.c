//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 50
#define MAX_LENGTH 20

int main(){

    char words[MAX_WORDS][MAX_LENGTH];
    char current_word[MAX_LENGTH];
    int num_words = 0, typing_time = 0, average_speed = 0, correct = 0, wrong = 0;

    printf("Welcome to the Typing Speed Test! You will be shown %d random words and your typing speed will be evaluated.\n", MAX_WORDS);
    printf("Please make sure to type the words exactly as you see them to ensure accurate results.\n");
    printf("Press enter to begin.\n");
    getchar();
    system("clear");

    srand(time(NULL)); // Random seed

    // Generate random words
    for(int i = 0; i < MAX_WORDS; i++){
        for(int j = 0; j < MAX_LENGTH; j++){
            char c = (char)(rand() % 26) + 'a'; // Generate random lowercase letter
            current_word[j] = c;
        }
        strcpy(words[i], current_word); // Add word to list of words
    }

    // Display words and calculate typing speed
    printf("Type the following words and press enter:\n");

    for(int i = 0; i < MAX_WORDS; i++){
        printf("%s\n", words[i]);

        // Get user input and remove newline character
        fgets(current_word, MAX_LENGTH, stdin);
        current_word[strcspn(current_word, "\n")] = 0;

        // Compare user input to correct word
        if(strcmp(current_word, words[i]) == 0){
            printf("Correct!\n");
            correct++;
        } else {
            printf("Wrong.\n");
            wrong++;
        }

        typing_time += strlen(current_word); // Add typing time for current word to total typing time
    }

    // Calculate average typing speed
    average_speed = (60 * MAX_WORDS) / typing_time;

    // Display results
    printf("Results:\n");
    printf("Correct words: %d\n", correct);
    printf("Wrong words: %d\n", wrong);
    printf("Average typing speed: %d WPM\n", average_speed);

    return 0;
}