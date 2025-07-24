//FormAI DATASET v1.0 Category: Word Count Tool ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

void sanitize_word(char *word) {
  for (int i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
    if (!isalpha(word[i])) {
      word[i] = '\0';
      break;
    }
  }
}

int is_word_counted(char **unique_words, int word_count, char *word) {
  for (int i = 0; i < word_count; i++) {
    if (strcmp(unique_words[i], word) == 0) {
      return 1;
    }
  }
  return 0;
}

void add_word_to_unique_words(char **unique_words, int *unique_word_count, char *word) {
  unique_words[*unique_word_count] = malloc(MAX_WORD_LENGTH * sizeof(char));
  strcpy(unique_words[*unique_word_count], word);
  (*unique_word_count)++;
}

void add_words_from_line(char **unique_words, int *unique_word_count, char *line) {
  char *word;
  word = strtok(line, " \n");
  while (word != NULL) {
    sanitize_word(word);
    if (strlen(word) > 0) {
      if (!is_word_counted(unique_words, *unique_word_count, word)) {
        add_word_to_unique_words(unique_words, unique_word_count, word);
      }
    }
    word = strtok(NULL, " \n");
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  char *filename = argv[1];
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: Could not open file %s\n", filename);
    return 1;
  }
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  char **unique_words = malloc(1000 * sizeof(char *));
  int unique_word_count = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    add_words_from_line(unique_words, &unique_word_count, line);
  }
  printf("Unique words: %d\n", unique_word_count);
  for (int i = 0; i < unique_word_count; i++) {
    printf("%s\n", unique_words[i]);
  }
  fclose(fp);
  if (line) {
    free(line);
  }
  for (int i = 0; i < unique_word_count; i++) {
    free(unique_words[i]);
  }
  free(unique_words);
  return 0;
}