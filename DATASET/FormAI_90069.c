//FormAI DATASET v1.0 Category: Text processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
  char line[MAX_LINE_LENGTH];
  char keyword[] = "future";
  int keyword_len = strlen(keyword);
  int keyword_count = 0;

  printf("Enter some text that contains the word 'future':\n");

  while (fgets(line, MAX_LINE_LENGTH, stdin)) {
    int line_len = strlen(line);
    int i = 0;

    while (i < line_len) {
      if (line[i] == keyword[0]) {
        int j = 0;
        int match = 1;

        while (j < keyword_len) {
          if (line[i+j] != keyword[j]) {
            match = 0;
            break;
          }
          j++;
        }

        if (match) {
          keyword_count++;
        }
      }

      i++;
    }

    if (feof(stdin)) {
      break;
    }
  }

  printf("\nNumber of times the word \"%s\" appears: %d\n", keyword, keyword_count);

  return 0;
}