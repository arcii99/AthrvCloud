//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_LENGTH 25

int main() {
    char words[MAX_WORDS][MAX_LENGTH] = {"apple", "banana", "cherry", "grape", "lemon", "mango", "orange", "peach", "pear", "watermelon"};
    int time_taken, correct_words = 0, total_words = 0;
    float typing_speed;

    srand(time(NULL)); // seeding the random function with current time
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following words as fast as you can:\n");

    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[rand() % MAX_WORDS]); // randomly selecting a word from the array
    }

    printf("\n");
    time_t start = time(NULL);

    char user_input[MAX_WORDS * MAX_LENGTH];
    fgets(user_input, sizeof(user_input), stdin); // reading user input

    time_taken = (int)(time(NULL) - start); // calculating the time spent by user

    char *token = strtok(user_input, " "); // breaking user input into tokens (words) using space as delimiter

    while (token != NULL) {
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]); // converting all characters to lowercase for comparison
        }

        if (strcmp(token, " ") != 0) { // ignoring spaces between words
            total_words++;
            for (int i = 0; i < MAX_WORDS; i++) {
                if (strcmp(token, words[i]) == 0) { // comparing user input with the words in array
                    correct_words++;
                }
            }
        }

        token = strtok(NULL, " ");
    }

    typing_speed = (float)(correct_words * 60) / time_taken; // calculating the typing speed in words per minute
    printf("You typed %d out of %d words correctly in %d seconds.\n", correct_words, total_words, time_taken);
    printf("Your typing speed is %.2f words per minute.\n", typing_speed);

    return 0;
}