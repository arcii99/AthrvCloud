//FormAI DATASET v1.0 Category: Text Summarizer ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
  char input[1000], summary[1000];
  int i, j, len, k = 0;

  printf("Hey there, I am your new text summarizer bot. Give me an input: \n");
  fgets(input, 1000, stdin);

  len = strlen(input);

  for (i = 0; i < len; i++) {
    if (input[i] == '.') {
      summary[k++] = input[i];
      for (j = i; j < len; j++) {
        if (input[j] == ' ') {
          i = j;
          break;
        }
        else {
          summary[k++] = input[j];
        }
      }
    }
  }

  printf("Here is your summary: \n%s", summary);

  printf("\nDon't be mad if your text seems a little choppy - I'm not a professional writer, I'm just a simple bot trying to make my way in the world.\n");

  return 0;
}