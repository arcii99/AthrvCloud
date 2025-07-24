//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main(){
    char input[100];
    int positive_score = 0, negative_score = 0;

    printf("Enter a sentence for sentiment analysis: \n");
    fgets(input, 100, stdin);

    char *ptr = strtok(input, " ");
    while(ptr != NULL){
        if(strcmp(ptr, "good") == 0 || strcmp(ptr, "great") == 0 || strcmp(ptr, "excellent") == 0 || strcmp(ptr, "fantastic") == 0){
            positive_score++;
        }
        else if(strcmp(ptr, "bad") == 0 || strcmp(ptr, "terrible") == 0 || strcmp(ptr, "awful") == 0 || strcmp(ptr, "horrible") == 0){
            negative_score++;
        }
        ptr = strtok(NULL, " ");
    }

    printf("Positive score: %d\n", positive_score);
    printf("Negative score: %d\n", negative_score);

    if(positive_score > negative_score){
        printf("Overall sentiment: Positive\n");
    }
    else if(positive_score < negative_score){
        printf("Overall sentiment: Negative\n");
    }
    else{
        printf("Overall sentiment: Neutral\n");
    }

    return 0;
}