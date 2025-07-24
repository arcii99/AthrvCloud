//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    char sentence[100];
    int i, n, chars_typed = 0;
    time_t start_time, end_time;
    double time_taken;
    srand(time(NULL));

    // Generate a random sentence
    char *words[] = {"apple", "banana", "cherry", "dragonfruit", "elderberry", "fig", "grape", "honeydew", "jackfruit", "kiwi", "lemon", "mango", "nectarine", "orange", "pineapple", "quince", "raspberry", "strawberry", "tangerine", "watermelon"};
    for (i = 0; i < 10; i++) {
        int r = rand() % 20;
        strcat(sentence, words[r]);
        strcat(sentence, " ");
    }
    printf("Type the following sentence as fast as you can: \n%s\n", sentence);

    // Start the timer
    time(&start_time);

    // Get user input
    fgets(sentence, 100, stdin);

    // End the timer
    time(&end_time);
    time_taken = difftime(end_time, start_time);

    // Calculate number of characters typed
    for (i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] != ' ' && sentence[i] != '\n') {
            chars_typed++;
        }
    }

    // Calculate typing speed
    double words_per_minute = chars_typed / 5.0 / (time_taken / 60.0);
    printf("You typed %d characters in %.2f seconds.\n", chars_typed, time_taken);
    printf("Your typing speed is %.2f words per minute.\n", words_per_minute);

    return 0;
}