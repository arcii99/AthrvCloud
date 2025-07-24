//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: real-life
#include <stdio.h>
#include <string.h>

// Function to perform sentiment analysis
void sentimentAnalysis(char* sentence) {
  int positive = 0, negative = 0, neutral = 0;
  char positiveWords[20][20] = {"good", "great", "excellent", "positive", "love", "like", "happy", "beautiful", "wonderful", "fantastic", "amazing", "awesome", "best", "nice", "fun", "cool", "joy", "smile", "win", "victory"};
  char negativeWords[20][20] = {"bad", "terrible", "awful", "negative", "hate", "dislike", "sad", "ugly", "disappointing", "horrible", "disgusting", "worst", "not", "mean", "unhappy", "annoying", "frustrated", "angry", "fail", "defeat"};

  // Splitting sentence into tokens
  char* token = strtok(sentence, " ");
  while(token != NULL) {
    for(int i=0; i<20; i++) {
      if(strcmp(token, positiveWords[i]) == 0) {
        positive++;
        break;
      }
      else if(strcmp(token, negativeWords[i]) == 0) {
        negative++;
        break;
      }
    }
    token = strtok(NULL, " ");
  }

  // Determining sentiment based on word count
  if(positive > negative) {
    printf("\nOverall Sentiment: Positive\n");
  }
  else if(negative > positive) {
    printf("\nOverall Sentiment: Negative\n");
  }
  else {
    printf("\nOverall Sentiment: Neutral\n");
  }
}

int main() {
  char sentence[100];
  printf("Enter a sentence for sentiment analysis:\n");
  fgets(sentence, 100, stdin);
  sentimentAnalysis(sentence);
  return 0;
}