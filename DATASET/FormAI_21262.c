//FormAI DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <string.h>

int wordCount(char *str) {
  int count = 0;
  int len = strlen(str);
  int i;
  int inWord = 0;
  
  for (i = 0; i < len; i++) {
    if (str[i] != ' ') {
      if (inWord == 0) {
        count++;
        inWord = 1;
      }
    }
    else {
      inWord = 0;
    }
  }
  
  return count;
}

int main() {
  char str[1000];
  
  printf("Enter a string: ");
  fgets(str, 1000, stdin);
  
  printf("Word count: %d\n", wordCount(str));
  
  return 0;
}