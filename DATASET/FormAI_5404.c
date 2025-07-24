//FormAI DATASET v1.0 Category: Text Summarizer ; Style: grateful
#include <stdio.h>
#include <string.h>
#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 1000

int main() {
  char text[MAX_INPUT_SIZE];
  char summary[MAX_OUTPUT_SIZE] = {0};
  
  printf("Welcome to the Grateful Text Summarizer!\n");
  printf("Please enter the text you would like to summarize:\n");
  
  fgets(text, MAX_INPUT_SIZE, stdin);
  
  printf("\nGreat! Now let's get started...\n\n");
  
  // tokenize the input text
  char *sentence = strtok(text, ".");
  int num_sentences = 0;
  while (sentence != NULL) {
    num_sentences++;
    sentence = strtok(NULL, ".");
  }
  
  // generate the summary
  if (num_sentences <= 1) {
    printf("Sorry, your text is too short to summarize.\n");
  } else {
    int summary_count = 0;
    sentence = strtok(text, ".");
    while (sentence != NULL && summary_count < 3) {
      strcat(summary, sentence);
      strcat(summary, ".");
      summary_count++;
      sentence = strtok(NULL, ".");
    }
    
    printf("Here is your summarized text:\n");
    printf("%s\n", summary);
    printf("\nThank you for using the Grateful Text Summarizer! Have a great day!\n");
  }
  
  return 0;
}