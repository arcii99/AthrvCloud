//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME 60
#define MAX_WORDS 10
#define MAX_LENGTH 20

int main() {
    const char *words[MAX_WORDS] = {"hello", "world", "programming", "language", "computer", "science", "algorithm", "software", "engineering", "keyboard"};
    int i, j, k, correct = 0, wrong = 0, count = 0, time_taken = 0;
    char input[MAX_LENGTH];
    time_t start, end;

    srand(time(NULL));

    printf("Welcome to the typing speed test\n");
    printf("You have %d seconds to type as many words as you can\n", MAX_TIME);

    start = time(NULL);
    while (time_taken < MAX_TIME) {
        i = rand() % MAX_WORDS;
        printf("Type word %d: %s\n", count + 1, words[i]);

        scanf("%s", input);

        if (!strcmp(input, words[i])) {
            correct++;
        } else {
            wrong++;
        }

        count++;
        time_taken = (int) difftime(time(NULL), start);
    }

    end = time(NULL);

    printf("\nTime taken: %d sec\n", MAX_TIME);
    printf("Words typed: %d\n", count);
    printf("Words correct: %d\n", correct);
    printf("Words wrong: %d\n", wrong);
    printf("Speed: %d WPM\n", (int) ((double) correct / (double) MAX_TIME * 60.0));

    return 0;
}