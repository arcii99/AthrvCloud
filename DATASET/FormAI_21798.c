//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to analyze sentiment of a given sentence
void analyzeSentiment(char sentence[]) {
    //List of positive and negative words
    char *positive_words[] = {"good", "happy", "great", "love", "excellent", "positive", "awesome", "perfect", "fantastic", "nice"};
    char *negative_words[] = {"bad", "sad", "terrible", "hate", "negative", "dislike", "awful", "poor", "pathetic", "horrible"};
    
    //Split the sentence into words
    char *ptr = strtok(sentence, " ");
    int positive_count = 0, negative_count = 0;
    while(ptr != NULL) {
        //Check if the word is positive or negative
        for(int i=0;i<10;i++) {
            if(strcmp(ptr, positive_words[i]) == 0) {
                positive_count++;
                break;
            }
            else if(strcmp(ptr, negative_words[i]) == 0){
                negative_count++;
                break;
            }
        }
        ptr = strtok(NULL, " ");
    }
    
    //Calculate sentiment score and print sentiment category
    int sentiment_score = positive_count - negative_count;
    if(sentiment_score > 0) {
        printf("Sentiment: Positive\n");
    }
    else if(sentiment_score < 0) {
        printf("Sentiment: Negative\n");
    }
    else {
        printf("Sentiment: Neutral\n");
    }
}

int main() {
    //Take input sentence from user
    char sentence[100];
    printf("Enter a sentence to analyze sentiment: ");
    fgets(sentence, 100, stdin);
    
    //Call analyzeSentiment function
    analyzeSentiment(sentence);
    
    return 0;
}