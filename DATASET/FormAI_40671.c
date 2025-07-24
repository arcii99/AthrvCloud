//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SENTENCE_LEN 1000
#define MAX_SUMMARY_LEN 200

char input_text[MAX_SENTENCE_LEN];
char summary_text[MAX_SUMMARY_LEN];

void* summarize(void* arg) {

  int num_sentences = *((int*) arg);
  int summary_position = 0;

  // split text into sentences
  char* start = input_text;
  char* end = input_text;
  for (int i = 0; i < num_sentences; i++) {

    // find end of sentence
    while (*end != '.' && *end != '?' && *end != '!' && *end != '\0') {
      end++;
    }

    // copy sentence to summary
    int sentence_len = end - start + 1;
    if (summary_position + sentence_len < MAX_SUMMARY_LEN) {
      for (int j = 0; j < sentence_len; j++) {
        summary_text[summary_position + j] = *(start + j);
      }
      summary_position += sentence_len;
      summary_text[summary_position - 1] = '\n'; // replace period with newline
    }

    // move to next sentence
    if (*end != '\0') {
      start = end + 1;
      end = start;
    }
    else {
      break;
    }
  }

  printf("Summary: %s\n", summary_text);
  return NULL;
}

int main() {

  // read input text
  printf("Enter text to summarize:\n");
  fgets(input_text, MAX_SENTENCE_LEN, stdin);

  // count number of sentences
  int num_sentences = 0;
  for (int i = 0; i < MAX_SENTENCE_LEN && input_text[i] != '\0'; i++) {
    if (input_text[i] == '.' || input_text[i] == '?' || input_text[i] == '!') {
      num_sentences++;
    }
  }

  // create worker thread to generate summary
  pthread_t worker;
  pthread_create(&worker, NULL, summarize, &num_sentences);
  pthread_join(worker, NULL);

  return 0;
}