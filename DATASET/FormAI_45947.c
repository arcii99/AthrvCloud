//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char input[1000];
  int positive = 0, negative = 0, neutral = 0;
  float positivity_rate, negativity_rate, neutrality_rate;
  printf("Enter the sentence: ");
  fgets(input, 1000, stdin);
  for (int i = 0; i < strlen(input); i++) {
    if (tolower(input[i]) == 'g') {
      positive++;
    } else if (tolower(input[i]) == 'b') {
      negative++;
    } else if (tolower(input[i]) == 'a') {
      neutral++;
    }
  }
  printf("\nAnalyzing...\n");
  if (positive >= negative && positive >= neutral) {
    printf("\nSentiment: Positive\n");
    positivity_rate = ((float)positive / strlen(input)) * 100;
    printf("Positivity Rate: %.2f%%", positivity_rate);
  } else if (negative >= positive && negative >= neutral) {
    printf("\nSentiment: Negative\n");
    negativity_rate = ((float)negative / strlen(input)) * 100;
    printf("Negativity Rate: %.2f%%", negativity_rate);
  } else {
    printf("\nSentiment: Neutral\n");
    neutrality_rate = ((float)neutral / strlen(input)) * 100;
    printf("Neutrality Rate: %.2f%%", neutrality_rate);
  }
  return 0;
}