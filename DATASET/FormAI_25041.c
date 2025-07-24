//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 25
#define MIN 5
#define TIMEOUT 10

char words[][MAX] = {"programming", "computer", "algorithm", "database", "software", "hardware", "function", "variable", "syntax", "pointer",
                     "compiler", "interpreter", "library", "network", "security", "memory", "operating", "system", "interface", "input", "output",
                     "file", "stream", "function", "namespace"};

int num_words = sizeof(words) / sizeof(words[0]);

void start_message() {
    printf("\nType as many words as you can in %d seconds ...\n", TIMEOUT);
}

void print_words() {
    printf("\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

void shuffle_words() {
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        char temp[MAX];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }
}

int main() {
    srand(time(0));

    shuffle_words();

    start_message();
    print_words();

    int correct_words = 0;
    int total_words = 0;
    time_t start_time, end_time;

    start_time = time(NULL);

    while (1) {
        char input[MAX];
        scanf("%s", input);

        total_words++;

        for (int i = 0; i < num_words; i++) {
            if (strcmp(input, words[i]) == 0) {
                correct_words++;
                break;
            }
        }

        end_time = time(NULL);
        if ((end_time - start_time) >= TIMEOUT) {
            break;
        }
    }

    printf("\n\nYou typed %d out of %d words correctly in %d seconds.\n", correct_words, total_words, TIMEOUT);

    return 0;
}