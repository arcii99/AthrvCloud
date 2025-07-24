//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#include <stdio.h>

int main() {
  char text[1000];
  int flag = 0;

  printf("Enter some text: ");
  fgets(text, 1000, stdin);

  for(int i = 0; text[i] != '\0'; i++) {
    if(text[i] == 'c') {
      if(text[i+1] == 'l' && text[i+2] == 'i' && text[i+3] == 'c' && text[i+4] == 'k' && text[i+5] == 's') {
        flag = 1;
        break;
      }
    }
    else if(text[i] == 's') {
      if(text[i+1] == 'p' && text[i+2] == 'a' && text[i+3] == 'm') {
        flag = 1;
        break;
      }
    }
  }

  if(flag) {
    printf("SPAM DETECTED!\n");
  }
  else {
    printf("Clean text. No spam detected.\n");
  }

  return 0;
}