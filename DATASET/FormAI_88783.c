//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1000  // Maximum input buffer size
#define MAX_SENTENCES 100 // Maximum number of sentences

int main() {
  char buffer[MAX_BUFFER];               // Input buffer
  char *sentences[MAX_SENTENCES];        // Array to hold sentences
  int count_sentences = 0;              // Count of the number of sentences
  int sentiment_score = 0;               // Sentiment score for the input text
  
  // Prompt user for input text
  printf("Please enter text: ");
  
  // Read input text into buffer
  fgets(buffer, MAX_BUFFER, stdin);
  
  // Tokenize the input text into sentences
  char *sentence = strtok(buffer, ".!?");
  while (sentence != NULL && count_sentences < MAX_SENTENCES) {
    sentences[count_sentences++] = sentence;
    sentence = strtok(NULL, ".!?");
  }
  
  // Analyze each sentence for sentiment score
  for (int i = 0; i < count_sentences; i++) {
    // Split sentence into words
    char *word = strtok(sentences[i], " ");
    while (word != NULL) {
      // Check for positive words
      if (strcmp(word, "great") == 0 || strcmp(word, "wonderful") == 0 || strcmp(word, "amazing") == 0) {
        sentiment_score++;
      }
      // Check for negative words
      else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "horrible") == 0) {
        sentiment_score--;
      }
      // Move to next word
      word = strtok(NULL, " ");
    }
  }
  
  // Print sentiment score
  printf("Sentiment score: %d\n", sentiment_score);
  
  return 0;
}