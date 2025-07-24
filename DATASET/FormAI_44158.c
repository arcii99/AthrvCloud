//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_STR_LEN 1000
#define MAX_SECONDS 60

int main()
{
    char input_str[MAX_STR_LEN];
    char dictionary[MAX_STR_LEN];
    int i = 0, j = 0, correct_count = 0, wrong_count = 0, seconds_left = MAX_SECONDS;
    double typing_speed = 0.0;
    time_t start_time, end_time;

    // Open dictionary file and read content
    FILE *fp = fopen("dictionary.txt", "r");
    if (!fp) {
        printf("Error opening dictionary file!\n");
        return -1;
    }
    while (fgets(dictionary, MAX_STR_LEN, fp) != NULL) {
        // Remove newline character from end of string
        dictionary[strcspn(dictionary, "\n")] = '\0';
    }
    fclose(fp);  // Close dictionary file

    printf("Welcome to the typing speed test!\n\nYou have %d seconds to type as many words as possible.\n\nPress Enter to start.", MAX_SECONDS);
    fgets(input_str, MAX_STR_LEN, stdin);  // Wait for Enter key

    time(&start_time);  // Record start time

    while (seconds_left > 0) {
        // Generate random word from dictionary
        char word[MAX_STR_LEN];
        for (i = 0, j = 0; dictionary[j] != '\0'; j++) {
            if (isspace(dictionary[j])) {
                word[i] = '\0';
                j++;
                break;
            }
            word[i++] = dictionary[j];
        }

        printf("\n%s : ", word);
        fgets(input_str, MAX_STR_LEN, stdin);

        if (strcmp(input_str, word) == 0) {
            correct_count++;
            printf("Correct! ");
        } else {
            wrong_count++;
            printf("Incorrect. ");
        }

        // Calculate time left
        time(&end_time);
        seconds_left = MAX_SECONDS - difftime(end_time, start_time);

        printf("Time left: %d seconds\n", seconds_left);
    }

    typing_speed = (double) (correct_count + wrong_count) / MAX_SECONDS;  // Calculate typing speed

    printf("\n\nTime's up!\n");
    printf("Correct words: %d\nIncorrect words: %d\nTyping speed: %.2f words per second\n", correct_count, wrong_count, typing_speed);

    return 0;
}