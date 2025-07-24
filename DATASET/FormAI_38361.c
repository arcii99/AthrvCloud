//FormAI DATASET v1.0 Category: Text Summarizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOC_LEN 1000
#define MAX_SENT_LEN 100

char *get_sentence(char *doc, int start, int end) {
  char *sentence = (char *)malloc(MAX_SENT_LEN * sizeof(char));
  int i, j;
  for (i = start, j = 0; i <= end; i++, j++) {
    sentence[j] = doc[i];
  }
  sentence[j] = '\0';
  return sentence;
}

int is_sentence_end(char c) {
  return (c == '.' || c == '?' || c == '!');
}

int get_next_sentence_start(char *doc, int start, int end) {
  int i;
  for (i = start; i <= end; i++) {
    if (doc[i] == '\n' || is_sentence_end(doc[i])) {
      return i+1;
    }
  }
  return -1;
}

int get_sentence_score(char *sentence) {
  int i, count = 0;
  char *token = strtok(sentence, " ");
  while (token) {
    count++;
    token = strtok(NULL, " ");
  }
  return count;
}

int get_doc_summary(char *doc, int len, char *summary, int max_summary_len) {
  int start = 0, end = 0, summary_len = 0;
  while (end < len) {
    end = get_next_sentence_start(doc, start, len-1);
    if (end == -1) break;
    char *sentence = get_sentence(doc, start, end-1);
    int score = get_sentence_score(sentence);
    if (summary_len + strlen(sentence) < max_summary_len) {
      strcat(summary, sentence);
      strcat(summary, " ");
      summary_len += strlen(sentence) + 1;
    }
    if (score > 10) break;
    start = end;
  }
  return 0;
}

int main() {
  char doc[MAX_DOC_LEN] = "This is an example document. It is used to demonstrate the functionality of the C text summarizer program. Once the program has processed the document, it will create a summary that contains only the most important sentences. The summary should be a condensed version of the original document that still conveys the main idea. The C text summarizer works by analyzing the text and using a scoring system to determine which sentences are most important. This is done by counting the number of words in each sentence. Sentences with a high word count are considered less important, while sentences with a low word count are considered more important. The program also takes into account sentence structure and other factors that may affect sentence importance. Overall, the C text summarizer is a useful tool for condensing large amounts of text into a shorter, more manageable form.";

  char summary[MAX_DOC_LEN] = "";
  get_doc_summary(doc, strlen(doc), summary, MAX_DOC_LEN);
  
  printf("Original Document:\n%s\n\n", doc);
  printf("Summary:\n%s\n", summary);
  
  return 0;
}