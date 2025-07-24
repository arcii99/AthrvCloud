//FormAI DATASET v1.0 Category: Text Summarizer ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main() {
  char input_text[1000];
  char summary[1000];
  int summary_length = 0;
  int word_count = 0;

  printf("Welcome to the Text Summarizer! Please enter the text you want to summarize:\n");
  fgets(input_text, 1000, stdin);

  for(int i=0; i<strlen(input_text); i++) {
    if(input_text[i] == ' ' || input_text[i] == '\n' || input_text[i] == '\0') {
      word_count++;
      if(word_count % 3 == 1) {
        continue;
      } else if (word_count % 3 == 2) {
        for(int j=i-summary_length; j<i; j++){
          summary[j-i+summary_length] = input_text[j];
        }
        summary[summary_length] = ' ';
        summary_length++;
      } else {
        summary[summary_length] = '.';
        summary_length++;
      }
    }
  }

  printf("Here is your summarized text:\n");
  printf("%s\n", summary);

  return 0;
}