//FormAI DATASET v1.0 Category: Word Count Tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char sentence[1000];
    int count = 0, prev_space = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    if (strlen(sentence) > 0) {
        if (sentence[strlen(sentence) - 1] == '\n') {
            sentence[strlen(sentence) - 1] = '\0';
        }
    }

    printf("\nYour sentence contains the following words: \n");

    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            count++;
            printf("%d. %.*s\n", count, i - prev_space, sentence + prev_space);
            prev_space = i + 1;

            // Randomly skip a word
            if (rand() % 2 == 0) {
                i = prev_space;
                count--;
            }
        }
    }

    count++;
    printf("%d. %.*s\n", count, (int)strlen(sentence) - prev_space, sentence + prev_space);

    printf("\nTotal word count: %d\n", count);

    return 0;
}