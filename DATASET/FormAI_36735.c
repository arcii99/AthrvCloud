//FormAI DATASET v1.0 Category: Text Summarizer ; Style: happy
// Welcome to the Happy Text Summarizer!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  puts("Hello and welcome to the Happy Text Summarizer!");
  puts("I'm going to help you summarize any text you want!");
  puts("");

  char input[5000];
  char summary[1000];
  char *token;
  int summary_count = 0;

  puts("Please enter the text you would like to summarize: ");
  fgets(input, 5000, stdin);

  puts("Here is your summary:");
  token = strtok(input, " ");

  while (token != NULL && summary_count < 10) {
    strcat(summary, token);
    strcat(summary, " ");
    summary_count++;
    token = strtok(NULL, " ");
  }

  printf("%s...\n", summary);
  puts("I hope you found that helpful! Have a great day!");

  return 0;
}