//FormAI DATASET v1.0 Category: Text Summarizer ; Style: puzzling
// Welcome to the Text Summarizer Program!
// Can you solve the puzzle and get the summary of the text?
#include <stdio.h>
#include <string.h>

int main() {
  char text[1000];
  char summary[1000] = "The summary is: ";

  printf("Enter the text to summarize: ");
  fgets(text, 1000, stdin);

  char *word = strtok(text, " .,!?");
  int num_words = 0;

  while (word != NULL) {

    // Here is the puzzle!
    if (num_words % 3 == 0 && num_words <= 12) {
      strcat(summary, word);
      strcat(summary, " ");
    }

    num_words++;
    word = strtok(NULL, " .,!?");
  }

  printf("%s\n", summary);
  return 0;
}