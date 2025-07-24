//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {"programming", "algorithm", "computer", "language", "variable", "function", "array", "pointer", "memory", "structure"};
    int words_length[MAX_WORDS];
    int i, j, k, temp, total_length, typing_speed;
    time_t start_time, end_time;
    double time_difference;
    char user_input[100];

    srand(time(NULL));

    /* Calculate the length of each word */
    for (i = 0; i < MAX_WORDS; i++) {
        words_length[i] = strlen(words[i]);
    }

    /* Shuffle the words array */
    for (i = 0; i < MAX_WORDS; i++) {
        j = rand() % MAX_WORDS;
        k = rand() % MAX_WORDS;

        memcpy(&temp, &words[j], sizeof(int));
        memcpy(&words[j], &words[k], sizeof(int));
        memcpy(&words[k], &temp, sizeof(int));
    }

    /* Start the typing test */
    printf("Welcome to the typing speed test!\n");
    printf("Type the words shown as fast as you can.\n");
    printf("Press enter after each word and type 'done' when you finish.\n\n");

    total_length = 0;
    typing_speed = 0;
    for (i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i]);
        total_length += words_length[i];

        time(&start_time);
        fgets(user_input, 100, stdin); // Read user input
        time(&end_time);

        /* If user types 'done', end the test */
        if (strcmp(user_input, "done\n") == 0) {
            printf("\n\nTyping speed test ended.\n");
            break;
        }

        /* Calculate the time taken to type the word */
        time_difference = difftime(end_time, start_time);

        /* Calculate the typing speed */
        typing_speed += (int) ((words_length[i] / time_difference) * 60);
    }

    /* Calculate the average typing speed */
    if (total_length > 0) {
        typing_speed /= total_length;
    }

    /* Print the results */
    printf("\n\nTyping speed: %d WPM (words per minute)\n", typing_speed);
    printf("Total time taken: %d seconds\n", (int) time_difference);
    printf("Number of words typed: %d\n", i);

    return 0;
}