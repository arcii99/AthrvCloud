//FormAI DATASET v1.0 Category: Text Summarizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUMMARY_LENGTH 1000
#define MAX_SENTENCE_LENGTH 100

typedef struct {
  char sentence[MAX_SENTENCE_LENGTH];
  int ranking;
} sentence_t;

void get_sentences(const char *input_text, sentence_t *sentences, int *num_sentences);
void rank_sentences(sentence_t *sentences, int num_sentences);
void summarize_sentences(const sentence_t *sentences, int num_sentences, char *summary);

int main() {
  char input_text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec vel quam mollis, aliquam metus et, suscipit nisl. Nunc a est bibendum, ullamcorper lectus a, sollicitudin nisl. Vestibulum auctor, sapien non semper semper, quam ipsum sodales arcu, vel lobortis enim arcu vel quam. Sed a est nibh. Nam vulputate elit at convallis finibus. Etiam tincidunt risus sit amet felis gravida ultricies. Nulla facilisi. Fusce molestie tristique velit at sollicitudin.";

  sentence_t sentences[50];
  int num_sentences = 0;

  get_sentences(input_text, sentences, &num_sentences);
  rank_sentences(sentences, num_sentences);

  char summary[MAX_SUMMARY_LENGTH];
  summarize_sentences(sentences, num_sentences, summary);

  printf("Original Text:\n%s\n", input_text);
  printf("\nSummarized Text:\n%s\n", summary);

  return 0;
}

void get_sentences(const char *input_text, sentence_t *sentences, int *num_sentences) {
  *num_sentences = 0;
  char *input_copy = malloc(strlen(input_text) + 1);
  strcpy(input_copy, input_text);

  char *sentence_token = strtok(input_copy, ".");
  while(sentence_token) {
    sentence_t sentence;
    memset(sentence.sentence, 0, MAX_SENTENCE_LENGTH);
    strncpy(sentence.sentence, sentence_token, MAX_SENTENCE_LENGTH - 1);
    sentence.sentence[MAX_SENTENCE_LENGTH - 1] = '\0';

    sentences[*num_sentences] = sentence;

    *num_sentences += 1;
    if(*num_sentences >= 50) {
      break;
    }

    sentence_token = strtok(NULL, ".");
  }

  free(input_copy);
}

void rank_sentences(sentence_t *sentences, int num_sentences) {
  for(int i = 0; i < num_sentences; i++) {
    int num_words = 0;
    char *word_token = strtok(sentences[i].sentence, " ");
    while(word_token) {
      num_words += 1;
      word_token = strtok(NULL, " ");
    }

    sentences[i].ranking = num_words;
  }
}

void summarize_sentences(const sentence_t *sentences, int num_sentences, char *summary) {
  memset(summary, 0, MAX_SUMMARY_LENGTH);

  int summary_length = 0;
  for(int i = 0; i < num_sentences; i++) {
    if(summary_length + strlen(sentences[i].sentence) < MAX_SUMMARY_LENGTH) {
      strcat(summary, sentences[i].sentence);
      strcat(summary, ". ");
      summary_length += strlen(sentences[i].sentence) + 2;
    }
  }

  // Remove trailing space and period
  summary[strlen(summary) - 2] = '\0';
}