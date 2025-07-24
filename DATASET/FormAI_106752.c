//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <string.h>

int main() {
  char alienSentence[100];
  printf("Enter an alien language sentence: ");
  scanf("%[^\n]", alienSentence);

  char c;
  int isUpper = 0;
  int length = strlen(alienSentence);

  printf("\nTranslation: ");
  
  for(int i = 0; i < length; i++) {
    c = alienSentence[i];
    if(c == ' ') {
      printf(" ");
    } else {
      if(isUpper == 1) {
        if(c >= 'a' && c <= 'z') {
          printf("%c", c-32);
        } else {
          printf("%c", c);
        }
        isUpper = 0;
      } else {
        printf("%c", c);
        isUpper = 1;
      }
    }
  }
  return 0;
}