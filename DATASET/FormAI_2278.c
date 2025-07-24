//FormAI DATASET v1.0 Category: Spam Detection System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 25
#define MAX_LINE 256

char *spam_words[MAX_SPAM_WORDS];
int num_spam_words;

void init_spam_words(); 
int is_spam(char *line);
int contains_spam_word(char *word, char *line); 

int main() {
  char input[MAX_LINE];
  init_spam_words();

  printf("Enter a message:\n");

  while (fgets(input, MAX_LINE, stdin)) {
    if (is_spam(input)) {
      printf("SPAM DETECTED\n");
    } else {
      printf("Message is clean\n");
    }
    printf("Enter another message:\n");
  }

  for (int i = 0; i < num_spam_words; i++) {
    free(spam_words[i]);
  }

  return 0;
}

void init_spam_words() {
  char spam[MAX_LINE];
  FILE *spam_file;
  spam_file = fopen("spam_words.txt", "r");

  if (spam_file == NULL) {
    printf("Error: File not found\n");
    exit(1);
  }

  while (fgets(spam, MAX_LINE, spam_file)) {
    spam[strcspn(spam, "\n")] = 0;
    spam_words[num_spam_words++] = strdup(spam);
  }
  fclose(spam_file);
}

int is_spam(char *line) {
  for (int i = 0; i < num_spam_words; i++) {
    if (contains_spam_word(spam_words[i], line)) {
      return 1;
    }
  }
  return 0;
}

int contains_spam_word(char *word, char *line) {
  char *token;
  char copy[MAX_LINE];
  strcpy(copy, line);
  token = strtok(copy, " ");

  while (token != NULL) {
    if (strcmp(word, token) == 0) {
      return 1;
    }
    token = strtok(NULL, " ");
  }
  return 0;
}