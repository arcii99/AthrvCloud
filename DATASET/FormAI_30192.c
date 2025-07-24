//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: thoughtful
#include <stdio.h>
#include <string.h>

char * sentiments[5] = {"Positive", "Negative", "Neutral", "Mixed", "Unknown"};

int analyze_sentiment(char * sentence) {
    char * positive_words[] = {"love", "like", "great", "excellent", "good", "happy"};
    char * negative_words[] = {"hate", "dislike", "bad", "terrible", "awful", "unhappy"};
    int positive_count = 0;
    int negative_count = 0;
    int i = 0;
    char * token;
    char delimiters[] = " ,.-";
    token = strtok(sentence, delimiters);
    while(token != NULL) {
        for(i = 0; i < 6; i++) {
            if(strcmp(token, positive_words[i]) == 0) {
                positive_count++;
                break;
            }
        }
        for(i = 0; i < 6; i++) {
            if(strcmp(token, negative_words[i]) == 0) {
                negative_count++;
                break;
            }
        }
        token = strtok(NULL, delimiters);
    }

    if(positive_count > negative_count) {
        if(positive_count > (positive_count + negative_count)*0.6) {
            return 0;
        }
        else {
            return 2;
        }
    }
    else if(negative_count > positive_count) {
        if(negative_count > (positive_count + negative_count)*0.6) {
            return 1;
        }
        else {
            return 2;
        }
    }
    else {
        return 2;
    }
}

int main() {
    char sentence[100];
    int sentiment;
    printf("Enter a sentence to analyze sentiment:\n");
    fgets(sentence, 100, stdin);
    sentiment = analyze_sentiment(sentence);
    printf("Sentiment of the sentence is: %s", sentiments[sentiment]);
    return 0;
}