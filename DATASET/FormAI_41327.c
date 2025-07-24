//FormAI DATASET v1.0 Category: Word Count Tool ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int wordCount(char *str);

int main() {
  char *str = (char*)malloc(sizeof(char) * 1000);
  
  printf("Enter a sentence: ");
  fgets(str, 1000, stdin);

  int count = wordCount(str);
  printf("\nWord count: %d", count);

  free(str);
  return 0;
}

int wordCount(char *str) {
  int count = 0, flag = 0;
  for(int i = 0; i < strlen(str); i++) {
    if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
      flag = 0;
    }
    else {
      if(flag == 0) {
        count++;
        flag = 1;
      }
    }
  }
  return count;
}