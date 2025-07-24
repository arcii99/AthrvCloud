//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_WORDS 100
#define WORD_LEN 50

char words[NUM_WORDS][WORD_LEN];

// Helper function to shuffle array of words
void shuffleWords() {
    srand(time(NULL));
    for (int i = NUM_WORDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp[WORD_LEN];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }
}

int main(void) {
    int num_correct = 0;
    int total_time = 0;
    int max_time = 0;
    int min_time = 100000;

    // Fill array of words with sample text
    strcpy(words[0], "the");
    strcpy(words[1], "quick");
    strcpy(words[2], "brown");
    strcpy(words[3], "fox");
    strcpy(words[4], "jumps");
    strcpy(words[5], "over");
    strcpy(words[6], "the");
    strcpy(words[7], "lazy");
    strcpy(words[8], "dog");
    strcpy(words[9], "0123456789");

    for (int i = 0; i < NUM_WORDS; i++) {
        shuffleWords();
        printf("Type the following words:\n");
        for (int j = 0; j < NUM_WORDS; j++) {
            printf("%s ", words[j]);
        }
        printf("\n");
        char input[WORD_LEN * NUM_WORDS];
        fgets(input, sizeof input, stdin);
        strtok(input, "\n");
        char *token = strtok(input, " ");
        int word_count = 0;
        int time_elapsed = 0;
        clock_t start_time = clock();
        while (token) {
            if (strcmp(token, words[word_count++]) == 0) {
                num_correct++;
            }
            token = strtok(NULL, " ");
        }
        time_elapsed = (clock() - start_time) * 1000 / CLOCKS_PER_SEC;
        total_time += time_elapsed;
        if (time_elapsed > max_time) {
            max_time = time_elapsed;
        }
        if (time_elapsed < min_time) {
            min_time = time_elapsed;
        }
        printf("Time elapsed: %dms\n", time_elapsed);
        printf("Accuracy: %.2f%%\n", (float)num_correct / NUM_WORDS * 100.0);
    }
    printf("Typing test completed!\n");
    printf("Average time per test: %dms\n", total_time / NUM_WORDS);
    printf("Maximum time: %dms\n", max_time);
    printf("Minimum time: %dms\n", min_time);
    printf("Overall accuracy: %.2f%%\n", (float)num_correct / (NUM_WORDS * NUM_WORDS) * 100.0);

    return 0;
}