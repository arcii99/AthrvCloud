//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100
#define MIN_TIME 5

int main(void) {
    char sentence[MAX_LENGTH];
    int i, success_count, error_count, total_count, time_elapsed, typing_speed;
    time_t start_time, end_time;

    printf("Welcome to the Typing Speed Test Program!\n\n");
    printf("You will be given a sentence to type. Try to type it as accurately and quickly as possible.\n");
    printf("Press enter when you are ready...\n");
    getchar();

    // Generate random sentence
    printf("Generating sentence...\n");
    char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    int num_words = sizeof(words) / sizeof(words[0]);
    srand(time(NULL));
    for (i = 0; i < MAX_LENGTH; i++) {
        sentence[i] = words[rand() % num_words][0];
        if (i == MAX_LENGTH-1) sentence[i] = '.';
        else if (i % 10 == 9) sentence[i] = ' ';
    }
    printf("Sentence: %s\n", sentence);

    // Begin timer
    printf("\nTimer starts now! Press enter when you are done...\n");
    getchar();
    start_time = time(NULL);

    // Prompt user to type sentence
    printf("\nType the sentence above:\n");
    success_count = 0;
    error_count = 0;
    total_count = 0;
    while (1) {
        char c = getchar();
        if (c == '\n') break;
        if (c == sentence[total_count]) {
            success_count++;
        } else {
            error_count++;
        }
        total_count++;
    }

    // End timer
    end_time = time(NULL);
    time_elapsed = (int) (end_time - start_time);

    // Calculate typing speed and accuracy
    typing_speed = (int) ((float) total_count / (float) time_elapsed * 60);
    int accuracy = (int) (100.0 * (float) success_count / (float) total_count);

    // Display results
    printf("\nTime elapsed: %d seconds\n", time_elapsed);
    printf("Accuracy: %d%%\n", accuracy);
    printf("Typing speed: %d words per minute\n", typing_speed);

    // Determine pass/fail and provide feedback
    if (time_elapsed < MIN_TIME) {
        printf("\nSorry, you did not type the sentence fast enough. Try again.\n");
    } else if (accuracy < 90) {
        printf("\nSorry, your accuracy was not high enough. Try again.\n");
    } else {
        printf("\nCongratulations, you passed the typing speed test!\n");
    }

    return 0;
}