//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 100
#define MAX_TIME 60

int main() {

    char words[MAX_WORDS][MAX_WORD_LENGTH] = {
        "programming",
        "languages",
        "keyboard",
        "computer",
        "code",
        "debug",
        "algorithm",
        "function",
        "data",
        "file",
        "memory",
        "integer",
        "array",
        "structure",
        "testing",
        "syntax",
        "variable",
        "platform",
        "compiler",
        "source"
    };

    int num_words = 20;
    int count = 0;
    int correct = 0;
    char input[MAX_WORD_LENGTH];
    time_t start_time, end_time;

    srand((unsigned) time(NULL));

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type as many words correctly as you can in %d seconds.\n", MAX_TIME);
    printf("Press enter to begin.\n");
    getchar();

    start_time = time(NULL);

    while (difftime(time(NULL), start_time) < MAX_TIME) {
        int index = rand() % num_words;
        printf("%s ", words[index]);

        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;

        count++;

        if (strcmp(input, words[index]) == 0) {
            correct++;
        }
    }

    end_time = time(NULL);

    printf("\n\nResults:\n");
    printf("Time: %d seconds\n", (int) difftime(end_time, start_time));
    printf("Words typed: %d\n", count);
    printf("Words correct: %d\n", correct);
    printf("Words per minute: %d\n", (int) (((double) correct / (double) count) * 60));

    return 0;
}