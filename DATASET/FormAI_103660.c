//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 15
#define MAX_TIME 60

char *words[MAX_WORDS] = {"apple", "banana", "cherry", "daisy", "eagle", "football", "guitar", "heaven", "integrity", "jazz"};

int main() {
    srand(time(NULL));

    double start_time = (double) clock() / CLOCKS_PER_SEC;
    double end_time = start_time + MAX_TIME;

    printf("Type the following words:\n");

    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[rand() % MAX_WORDS]);
    }
    printf("\n");

    char word[MAX_WORD_LENGTH];
    int correct_words = 0;

    while ((double) clock() / CLOCKS_PER_SEC < end_time) {
        scanf("%s", word);
        if (strcmp(word, "exit") == 0) {
            break;
        }

        int j;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j]) == 0) {
                correct_words++;
                break;
            }
        }
    }

    printf("Time: %.1f seconds\n", MAX_TIME);
    printf("Words typed correctly: %d\n", correct_words);

    return 0;
}