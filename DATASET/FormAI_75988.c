//FormAI DATASET v1.0 Category: Spam Detection System ; Style: authentic
#include <stdio.h>
#include <string.h>

#define SPAM_SCORE_THRESHOLD 5

int main() {
    char* message = "Get rich quick! Buy our product now!";
    int spamWordsCount = 0;
    char* spamWords[] = {"rich", "buy", "product", "quick"};

    char* word = strtok(message, " ");
    while (word != NULL) {
        for (int i = 0; i < sizeof(spamWords)/sizeof(spamWords[0]); i++) {
            if (strcmp(word, spamWords[i]) == 0) {
                spamWordsCount++;
            }
        }
        word = strtok(NULL, " ");
    }

    if (spamWordsCount >= SPAM_SCORE_THRESHOLD) {
        printf("SPAM DETECTED! Spam score: %d\n", spamWordsCount);
    }
    else {
        printf("Not spam. Spam score: %d\n", spamWordsCount);
    }

    return 0;
}