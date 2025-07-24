//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: curious
#include<stdio.h>
#include<string.h>

int main(){

    char input[1000];
    int positive_count=0, negative_count=0;
    float sentiment_score;

    printf("Enter a sentence for sentiment analysis: ");
    fgets(input, 1000, stdin);

    char *word = strtok(input, " "); // Split the sentence into words

    while(word != NULL){
        // Check if the word is positive or negative 
        if(strcmp(word, "good")==0 || strcmp(word, "great")==0 || strcmp(word, "excellent")==0){
            positive_count++;
        }
        else if(strcmp(word, "bad")==0 || strcmp(word, "terrible")==0 || strcmp(word, "awful")==0){
            negative_count++;
        }

        word = strtok(NULL, " "); // Move to the next word
    }

    // Calculate the sentiment score
    sentiment_score = ((float)positive_count - (float)negative_count) / (float)(positive_count + negative_count);

    printf("\nSentiment Score: %.2f\n", sentiment_score);

    // Determine if the sentiment is positive or negative
    if(sentiment_score > 0){
        printf("Overall Sentiment: Positive\n");
    }
    else if(sentiment_score < 0){
        printf("Overall Sentiment: Negative\n");
    }
    else{
        printf("Overall Sentiment: Neutral\n");
    }

    return 0;
}