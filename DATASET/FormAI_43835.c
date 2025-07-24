//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_LEN 20
#define TIME_LIMIT 60

int main() {
    char words[MAX_WORDS][MAX_LEN];
    int i, j, count = 0, num_words = 0;
    time_t start_time, end_time;
    double time_taken;

    srand(time(NULL)); // seed the random number generator with current time

    // Store random words in the array
    char* all_words[] = {"apple", "banana", "cherry", "dog", "elephant", "fire", "guitar",
                         "house", "ice cream", "jelly", "kangaroo", "lion", "monkey", "number",
                         "ocean", "penguin", "queen", "rainbow", "sun", "tree", "umbrella",
                         "violin", "window", "xylophone", "yogurt", "zebra"};
    int num_all_words = sizeof(all_words) / sizeof(char*);
    for (i = 0; i < MAX_WORDS; i++) {
        int random_num = rand() % num_all_words;
        strcpy(words[i], all_words[random_num]);
        num_words++;
    }

    printf("Typing Speed Test - Type as many words as you can in %d seconds!\n\n", TIME_LIMIT);

    printf("Press ENTER to start the timer...");
    getchar();

    time(&start_time); // get the current time at the start

    // Loop until time limit is reached
    while (1) {
        printf("\n\n");

        // Print out the words to type
        for (i = 0; i < num_words; i++) {
            printf("%s ", words[i]);
        }

        printf("\n");

        // Read in the user's input
        char input_str[MAX_WORDS * MAX_LEN];
        fgets(input_str, sizeof(input_str), stdin);

        // Convert newline characters to null characters
        for (i = 0; i < strlen(input_str); i++) {
            if (input_str[i] == '\n') {
                input_str[i] = '\0';
            }
        }

        // Split the user's input into individual words
        char* input_words[MAX_WORDS];
        char* word = strtok(input_str, " ");
        i = 0;
        while (word != NULL) {
            input_words[i++] = word;
            word = strtok(NULL, " ");
        }

        // Check each word for correctness
        for (i = 0; i < num_words; i++) {
            if (i >= MAX_WORDS) {
                break;
            }

            if (strcmp(words[i], input_words[i]) == 0) {
                count++;
            }
        }

        time(&end_time); // get the current time at the end
        time_taken = difftime(end_time, start_time);

        // Check if time limit has been reached
        if (time_taken >= TIME_LIMIT) {
            break;
        }
    }

    printf("\n\nTime's up! You typed %d words in %.2f seconds.\n", count, time_taken);
    printf("Your typing speed was %.2f words per minute.\n\n", (count / time_taken) * 60);

    return 0;
}