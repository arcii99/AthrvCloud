//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int positiveWordsCount = 0;
    int negativeWordsCount = 0;
    char *positiveWords[] = {"happy", "excited", "good", "great", "love"};
    char *negativeWords[] = {"sad", "disappointed", "bad", "frustrated", "hate"};

    printf("Enter a sentence for sentiment analysis: ");
    fgets(sentence, 1000, stdin);

    char *word = strtok(sentence, " ");
    while (word != NULL) {
        for(int i = 0; i < sizeof(positiveWords)/sizeof(positiveWords[0]); i++) {
            if(strcmp(word, positiveWords[i]) == 0) {
                positiveWordsCount++;
            }
        }

        for(int i = 0; i < sizeof(negativeWords)/sizeof(negativeWords[0]); i++) {
            if(strcmp(word, negativeWords[i]) == 0) {
                negativeWordsCount++;
            }
        }

        word = strtok(NULL, " ");
    }

    if(positiveWordsCount > negativeWordsCount) {
        printf("\nSentiment analysis result: This sentence has a positive sentiment!\n");
    } else if (negativeWordsCount > positiveWordsCount){
        printf("\nSentiment analysis result: This sentence has a negative sentiment!\n");
    } else {
        printf("\nSentiment analysis result: This sentence is neutral.\n");
    }

    return 0;
}