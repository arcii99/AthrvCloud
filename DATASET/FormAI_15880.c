//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 100

int main() {
  char input[MAX_SENTENCES][MAX_WORDS];
  char output[MAX_SENTENCES][MAX_WORDS];
  char whole_text[MAX_SENTENCES * MAX_WORDS];
  int sentence_count = 0;

  printf("Welcome to the Surrealist Text Summarizer!\n");
  printf("Please input the text you want to summarize:\n");

  // Get user input
  while (fgets(input[sentence_count], MAX_WORDS, stdin)) {
    strcat(input[sentence_count], " ");
    strcat(whole_text, input[sentence_count]);
    sentence_count++;
    if (sentence_count == MAX_SENTENCES) {
      printf("Maximum sentence count reached, summarizing...\n");
      break;
    }
  }

  // Process text and generate output
  printf("Generating summary...\n");
  char *word = strtok(whole_text, " ");
  int output_sentence_count = 0;
  while (word != NULL && output_sentence_count < sentence_count/2) {
    strcpy(output[output_sentence_count], word);
    word = strtok(NULL, " ");
    if (word == NULL) break;
    strcat(output[output_sentence_count], " ");
    strcat(output[output_sentence_count], word);
    output_sentence_count++;
  }

  // Print output
  printf("Summary:\n");
  for (int i=0; i<output_sentence_count; i++) {
    printf("%s\n", output[i]);
  }

  printf("That's it! Ain't surrealism grand?\n");

  return 0;
}