//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sentiment_analysis(char sentence[]) {
  	int positive = 0, negative = 0, neutral = 0, overall_sentiment = 0;
  	char *token = strtok(sentence, " ");
  	while(token != NULL) {
    	if(strcmp(token, "good") == 0 || strcmp(token, "great") == 0 || strcmp(token, "excellent") == 0 || strcmp(token, "amazing") == 0) {
      		positive++;
    	} else if(strcmp(token, "bad") == 0 || strcmp(token, "poor") == 0 || strcmp(token, "terrible") == 0 || strcmp(token, "awful") == 0) {
      		negative++;
    	} else {
      		neutral++;
    	}
    	token = strtok(NULL, " ");
  	}
  	if(positive > negative && positive > neutral) {
    	overall_sentiment = 1;
  	} else if(negative > positive && negative > neutral) {
    	overall_sentiment = -1;
  	} else {
    	overall_sentiment = 0;
  	}
  	return overall_sentiment;
}

int main() {
  	char sentence[1000];
  	printf("Enter a sentence: ");
  	fgets(sentence, sizeof(sentence), stdin);
  	int sentiment = sentiment_analysis(sentence);
  	if(sentiment == 1) {
    	printf("\nPositive Sentiment");
  	} else if(sentiment == -1) {
    	printf("\nNegative Sentiment");
  	} else {
    	printf("\nNeutral Sentiment");
  	}
  	return 0;
}