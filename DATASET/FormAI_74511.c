//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: immersive
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int positive_score = 0, negative_score = 0;
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    char *token;
    token = strtok(sentence, " ");
    while(token != NULL){
        if(strcmp(token, "good") == 0 || strcmp(token, "happy") == 0 || strcmp(token, "excellent") == 0){
            positive_score++;
        }
        else if(strcmp(token, "bad") == 0 || strcmp(token, "sad") == 0 || strcmp(token, "terrible") == 0){
            negative_score++;
        }
        token = strtok(NULL, " ");
    }
    if(positive_score > negative_score){
        printf("This sentence has a positive sentiment.");
    }
    else if(negative_score > positive_score){
        printf("This sentence has a negative sentiment.");
    }
    else {
        printf("This sentence has a neutral sentiment.");
    }
    return 0;
}