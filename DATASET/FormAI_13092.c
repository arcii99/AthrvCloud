//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

void to_lowercase(char *str) {
  int i = 0;
  while (str[i]) {
    str[i] = tolower(str[i]);
    i++;
  }
}

int main(int argc, char *argv[]) {
  
  if (argc != 2) {
    printf("Please input the file name\n");
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (!fp) {
    printf("Failed to open file\n");
    return EXIT_FAILURE;
  }

  int count = 0;
  char word[MAX_WORD_LENGTH];
  char c;
  int i = 0;
  int j;
  int k;
  char words[1000][MAX_WORD_LENGTH]; // assume file contains less than 1000 words
  int freq[1000] = {0}; // assume no word is repeated more than 1000 times

  while ((c = fgetc(fp)) != EOF) {

    if (isalpha(c)) {
      word[i++] = c;
    }
    else if (c == ' ' || c == '\n' || c == '\t') {
      if (i > 0) {
        word[i] = '\0';
        to_lowercase(word);

        for (j = 0; j < count; j++) {
          if (strcmp(words[j], word) == 0) {
            freq[j]++;
            break;
          }
        }

        if (j == count) {
          strcpy(words[count], word);
          freq[count]++;
          count++;
        }

        i = 0;
      }
    }
  }
  
  printf("Word\t\t\tFrequency\n");

  for (k = 0; k < count; k++) {
    printf("%-20s\t%d\n", words[k], freq[k]);
  }

  fclose(fp);

  return EXIT_SUCCESS;
}