//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: automated
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    int length = strlen(sentence);
    int positiveCount = 0;
    int negativeCount = 0;

    for (int i = 0; i < length; i++) {
        if (sentence[i] == 'g') {
            if (i + 1 < length && sentence[i + 1] == 'o') {
                positiveCount++;
                i++;
            }
        } else if (sentence[i] == 'n') {
            if (i + 1 < length && sentence[i + 1] == '\'') {
                if (i + 2 < length && sentence[i + 2] == 't') {
                    negativeCount++;
                    i+=2;
                }
            } else if (i + 1 < length && sentence[i + 1] == 'o') {
                negativeCount++;
                i++;
            }
        }
    }

    if (positiveCount > negativeCount) {
        printf("This sentence has a positive sentiment");
    } else if (positiveCount < negativeCount) {
        printf("This sentence has a negative sentiment");
    } else {
        printf("This sentence has a neutral sentiment");
    }

    return 0;
}