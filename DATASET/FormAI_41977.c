//FormAI DATASET v1.0 Category: Syntax parsing ; Style: lively
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char sentence[100];
  char word[20];
  int i, j = 0, k = 0;

  printf("Enter a sentence: ");
  fgets(sentence, 100, stdin);

  printf("\nYour sentence turned into an array of words:\n");

  for (i = 0; i < strlen(sentence); i++) {
    if (!isspace(sentence[i])) {
      word[j] = sentence[i];
      j++;
    } else {
      word[j] = '\0';
      printf("%d : %s\n", k, word);
      k++;
      j = 0;
    }
  }
  
  word[j] = '\0';
  printf("%d : %s\n", k, word);

  return 0;
}