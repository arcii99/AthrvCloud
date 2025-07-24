//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sentence[100];
    int positiveCount = 0;
    int negativeCount = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == 'g' && sentence[i + 1] == 'o' && sentence[i + 2] == 'o' && sentence[i + 3] == 'd') {
            positiveCount++;
        }
        if (sentence[i] == 'b' && sentence[i + 1] == 'a' && sentence[i + 2] == 'd') {
            negativeCount++;
        }
    }

    if (positiveCount > negativeCount) {
        printf("This sentence has a positive sentiment!\n");
    } else if (negativeCount > positiveCount) {
        printf("This sentence has a negative sentiment.\n");
    } else {
        printf("This sentence is neutral.\n");
    }

    return 0;
}