//FormAI DATASET v1.0 Category: Text Summarizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 1000

int main(void) {

  char sentence[MAX_VALUE];
  memset(sentence, '\0', sizeof(sentence));

  printf("\nEnter the text to summarize:\n");
  fgets(sentence, MAX_VALUE, stdin);

  char *token = strtok(sentence, " ");
  int count = 0;
  while (token) {
    count++;
    if (count <= 10) {
      printf("%s ", token);
    }
    token = strtok(NULL, " ");
  }

  printf("\n");

  return EXIT_SUCCESS;
}