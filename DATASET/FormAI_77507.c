//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sentence[100];
    int positiveWords = 0, negativeWords = 0, i, j;
    char* positiveList[10] = {"happy", "joy", "great", "fun", "excited", "love", "wonderful", "amazing", "fantastic", "awesome"};
    char* negativeList[10] = {"sad", "angry", "frustrated", "disappointed", "annoyed", "hate", "terrible", "horrible", "awful", "bad"};
    
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    char* word = strtok(sentence, " ");
    while(word != NULL) {
        for(i = 0; i < 10; i++) {
            if(strcmp(word, positiveList[i]) == 0) {
                positiveWords++;
            }
            else if(strcmp(word, negativeList[i]) == 0) {
                negativeWords++;
            }
        }
        word = strtok(NULL, " ");
    }

    if(positiveWords > negativeWords) {
        printf("The sentence has a positive sentiment.\n");
    }
    else if(negativeWords > positiveWords) {
        printf("The sentence has a negative sentiment.\n");
    }
    else {
        printf("The sentence is neutral.\n");
    }

    return 0;
}