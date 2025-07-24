//FormAI DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define DICT_SIZE 1024

char *dictionary[DICT_SIZE]; // Array of pointers to dictionary words
int dict_len = 0; // Number of words in the dictionary

int load_dictionary(const char *dict_file);
void lowercase(char *str);
int check_word(const char *word);

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s <dictionary_file> <input_file>\n", argv[0]);
    return 1;
  }

  if (load_dictionary(argv[1])) {
    printf("Failed to load dictionary file\n");
    return 1;
  }

  FILE *input_file = fopen(argv[2], "r");
  if (!input_file) {
    printf("Failed to open input file\n");
    return 1;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, input_file)) {
    char *word = strtok(line, " \t\n");
    while (word != NULL) {
      lowercase(word);
      if (!check_word(word)) {
        printf("Unknown word: %s\n", word);
      }
      word = strtok(NULL, " \t\n");
    }
  }

  fclose(input_file);
  return 0;
}

int load_dictionary(const char *dict_file) {
  FILE *dict = fopen(dict_file, "r");
  if (!dict) {
    return 1;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, dict)) {
    char *word = strtok(line, "#\n"); // Ignore comments and newlines
    while (word != NULL) {
      dictionary[dict_len++] = strdup(word);
      word = strtok(NULL, "#\n");
    }
  }

  fclose(dict);
  return 0;
}

void lowercase(char *str) {
  for (int i = 0; str[i]; i++) {
    str[i] = tolower(str[i]);
  }
}

int check_word(const char *word) {
  for (int i = 0; i < dict_len; i++) {
    if (strcmp(dictionary[i], word) == 0) {
      return 1;
    }
  }
  return 0;
}