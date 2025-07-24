//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[1000];

  printf("Enter a sentence: ");
  fgets(sentence, sizeof(sentence), stdin);

  int num_positive = 0, num_negative = 0;

  char* positive_words[] = {"love", "happy", "awesome", "great", "excited"};
  char* negative_words[] = {"hate", "sad", "awful", "terrible", "disappointed"};

  char* token = strtok(sentence, " ");  // tokenize sentence by space

  while (token != NULL) {
    for (int i = 0; i < 5; i++) {  // check for positive words
      if (strstr(token, positive_words[i]) != NULL) {
        num_positive++;
        break;
      }
    }
    for (int i = 0; i < 5; i++) {  // check for negative words
      if (strstr(token, negative_words[i]) != NULL) {
        num_negative++;
        break;
      }
    }

    token = strtok(NULL, " ");  // get next token
  }

  if (num_positive > num_negative) {
    printf("\nSentiment analysis result:\nThis sentence has a positive sentiment.\n");
  }
  else if (num_positive < num_negative) {
    printf("\nSentiment analysis result:\nThis sentence has a negative sentiment.\n");
  }
  else {
    printf("\nSentiment analysis result:\nThis sentence has a neutral sentiment.\n");
  }

  return 0;
}