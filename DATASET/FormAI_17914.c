//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main() {
  char sentence[1000];
  int positiveCount = 0, negativeCount = 0, neutralCount = 0;
  float positivityScore, negativityScore, neutralityScore;
  
  printf("Enter a sentence to get its sentiment analysis: ");
  fgets(sentence, 1000, stdin);

  char positiveWords[4][10] = {"good", "great", "awesome", "excellent"};
  char negativeWords[4][10] = {"bad", "terrible", "horrible", "awful"};

  char* token = strtok(sentence, " ");
  
  while (token != NULL) {
    for (int i = 0; i < 4; i++) {
      if (strcmp(token, positiveWords[i]) == 0) {
        positiveCount++;
        break;
      }
      else if (strcmp(token, negativeWords[i]) == 0) {
        negativeCount++;
        break;
      }
      else if (i == 3) {
        neutralCount++;
      }
    }
    token = strtok(NULL, " ");
  }

  positivityScore = (float)positiveCount/strlen(sentence);
  negativityScore = (float)negativeCount/strlen(sentence);
  neutralityScore = (float)neutralCount/strlen(sentence);

  printf("Positive Exclamations: %d\n", positiveCount);
  printf("Negative Exclamations: %d\n", negativeCount);
  printf("Neutral Exclamations: %d\n", neutralCount);

  printf("Positivity Score: %.2f\n", positivityScore);
  printf("Negativity Score: %.2f\n", negativityScore);
  printf("Neutrality Score: %.2f\n", neutralityScore);

  if (positivityScore > negativityScore && positivityScore > neutralityScore) {
    printf("The sentence is predominantly positive.");
  }
  else if (negativityScore > positivityScore && negativityScore > neutralityScore) {
    printf("The sentence is predominantly negative.");
  }
  else {
    printf("The sentence is predominantly neutral.");
  }

  return 0;
}