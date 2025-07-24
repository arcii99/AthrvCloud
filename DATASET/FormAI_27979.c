//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: funny
#include <stdio.h>

int main() {
  char sentence[100];
  int happyCount = 0;
  int sadCount = 0;
  int neutralCount = 0;
  
  printf("Hey there, I'm a sentiment analysis tool. Tell me something funny!\n");
  scanf("%[^\n]", sentence);
  
  for (int i = 0; sentence[i] != '\0'; i++) {
    switch(sentence[i]) {
      case ':':
        if (sentence[i+1] == ')') {
          happyCount++;
          i++;
        }
        else if (sentence[i+1] == '(') {
          sadCount++;
          i++;
        }
        break;
      default:
        neutralCount++;
    }
  }
  
  printf("Wow, you're hilarious! Let me analyze that...\n");
  
  if (happyCount > sadCount && happyCount > neutralCount) {
    printf("You're a comedy genius! Your statement is %d%% happy.", (happyCount*100)/(happyCount+sadCount+neutralCount));
  }
  else if (sadCount > happyCount && sadCount > neutralCount) {
    printf("Aww, don't be sad! Your statement is %d%% sad.", (sadCount*100)/(happyCount+sadCount+neutralCount));
  }
  else {
    printf("Well, you didn't make me laugh or cry. Your statement is %d%% neutral.", (neutralCount*100)/(happyCount+sadCount+neutralCount));
  }
  
  return 0;
}