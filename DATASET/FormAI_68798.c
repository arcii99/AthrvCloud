//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    int positive_count = 0, negative_count = 0, neutral_count = 0;

    char positive_words[5][10] = {"good", "nice", "great", "excellent", "wonderful"};
    char negative_words[5][10] = {"bad", "terrible", "poor", "awful", "horrible"};

    char *token = strtok(sentence, " ");

    while(token != NULL){
        for(int i=0; i<5; i++){
            if(strcmp(token, positive_words[i]) == 0){
                positive_count++;
            }
            if(strcmp(token, negative_words[i]) == 0){
                negative_count++;
            }
        }
        token = strtok(NULL, " ");
    }

    neutral_count = strlen(sentence) - (positive_count + negative_count);

    printf("\n\t[Sentiment Analysis]\n");
    printf("\nPositive words: %d", positive_count);
    printf("\nNegative words: %d", negative_count);
    printf("\nNeutral words: %d", neutral_count);

    if(positive_count > negative_count){
        printf("\nThe sentence is Positive.");
    }
    else if (negative_count > positive_count){
        printf("\nThe sentence is Negative.");
    }
    else{
        printf("\nThe sentence is Neutral.");
    }

    return 0;
}