//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: authentic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 20
#define MAX_WORD_LEN 10
#define TEST_TIME 30

char words[MAX_WORDS][MAX_WORD_LEN] = {"programming", "keyboard", "language", "computer", "software", "developer", "syntax", "algorithm", "database", "interface", "network", "cyberspace", "encryption", "webpage", "firewall", "debugging", "microcontroller", "logic", "kernel", "virtualization"};
int total_words = sizeof(words) / sizeof(words[0]);

int main() {
    int typed_words = 0, correct_words = 0;
    char input;
    time_t start_time, current_time;

    srand(time(NULL));
    printf("Welcome to the typing speed test!\n");
    printf("You will be given %d seconds to type as many words as you can.\n", TEST_TIME);
    printf("Enter the words without spaces and press enter to submit.\n");
    printf("Press any key to start ...\n");
    getchar();

    start_time = time(NULL);
    do {
        int random_word = rand() % total_words;
        printf("%s ", words[random_word]);
        scanf("%s", &input);
        typed_words++;

        if (strcmp(words[random_word], &input) == 0) {
            printf("✓\n");
            correct_words++;
        } else {
            printf("✕\n");
        }

        current_time = time(NULL);
    } while (current_time - start_time < TEST_TIME);

    printf("\n\nTest has ended, here are your results:\n");
    printf("Typed %d words in %d seconds.\n", typed_words, TEST_TIME);
    printf("You have typed %d correctly and %d incorrectly.\n", correct_words, typed_words - correct_words);
    printf("WPM: %f\n", (float)correct_words / (float)TEST_TIME * 60);
    printf("Accuracy: %f%%\n", (float)correct_words / (float)typed_words * 100);

    return 0;
}