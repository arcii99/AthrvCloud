//FormAI DATASET v1.0 Category: Text Summarizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUMMARY_LEN 100
#define MAX_TEXT_LEN 10000
#define MAX_SENTENCE_NUM 1000

// function prototypes
void summarizeText(char *text, char *summary);

int main() {
  char text[MAX_TEXT_LEN], summary[MAX_SUMMARY_LEN];
  
  // read text from the user
  printf("Enter text to be summarized (Max %d characters):\n", MAX_TEXT_LEN);
  fgets(text, MAX_TEXT_LEN, stdin);

  // call the summarization function
  summarizeText(text, summary);

  // display the summary
  printf("The summarized text is:\n%s\n", summary);
  
  return 0;
}

/**
 * This is the core function that summarizes the given text.
 * The function takes two arguments:
 *   1. A pointer to the input text string.
 *   2. A pointer to the output summary string.
 */
void summarizeText(char *text, char *summary) {
  
  // split the input text into sentences
  char sentences[MAX_SENTENCE_NUM][MAX_TEXT_LEN];
  int sentence_count = 0, begin_index = 0, end_index = 0;
  while (text[end_index] != '\0') {
    if (text[end_index] == '.' || text[end_index] == '?' || text[end_index] == '!') {
      // found a sentence boundary, so extract the sentence
      int len = end_index - begin_index + 1;
      strncpy(sentences[sentence_count], &text[begin_index], len);
      sentences[sentence_count][len] = '\0';
      sentence_count++;
      begin_index = end_index + 1;
    }
    end_index++;
  }
  
  // initialize the summary
  memset(summary, 0, MAX_SUMMARY_LEN);
  
  // analyze each sentence and add the relevant ones to the summary
  int summary_len = 0, i;
  for (i = 0; i < sentence_count && summary_len < MAX_SUMMARY_LEN; i++) {
    
    // check if the sentence is important
    int is_important = 0;
    char *token = strtok(sentences[i], " ");
    while (token != NULL && !is_important) {
      if (isdigit(token[0])) {
        // ignore sentences with numbers
        is_important = 0;
      } else if (strcmp(token, "is") == 0 || strcmp(token, "are") == 0) {
        // ignore sentences with "is" or "are"
        is_important = 0;
      } else {
        // sentence has some value
        is_important = 1;
      }
      token = strtok(NULL, " ");
    }
    
    if (is_important) {
      // add the sentence to the summary
      strcat(summary, sentences[i]);
      summary_len += strlen(sentences[i]);
    }
  }
  
  // trim the summary to the maximum allowed length
  if (summary_len > MAX_SUMMARY_LEN) {
    summary[MAX_SUMMARY_LEN - 3] = '.';  // add an ellipsis to indicate that the summary is truncated
    summary[MAX_SUMMARY_LEN - 2] = '.'; 
    summary[MAX_SUMMARY_LEN - 1] = '.';
    summary[MAX_SUMMARY_LEN] = '\0';
  }
}