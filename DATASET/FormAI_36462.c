//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter some text: ");
  scanf("%[^\n]%*c", input);
  
  int happy = 0;
  int sad = 0;
  int i;
  for (i = 0; i < strlen(input); i++) {
    // Check for happy emoticons
    if (input[i] == ':' && input[i+1] == ')') {
      happy++;
    }
    // Check for sad emoticons
    if (input[i] == ':' && input[i+1] == '(') {
      sad++;
    }
  }
  
  printf("\nSentiment Analysis Results:\n");
  printf("Happy count: %d\n", happy);
  printf("Sad count: %d\n", sad);
  
  if (happy > sad) {
    printf("You seem pretty happy today, keep it up!\n");
  } else if (sad > happy) {
    printf("I'm sorry to hear that you're feeling down, hope your day gets better.\n");
  } else {
    printf("Looks like you're feeling pretty neutral today, that's okay too!\n");
  }
  
  return 0;
}