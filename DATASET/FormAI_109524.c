//FormAI DATASET v1.0 Category: Text Summarizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define MAX_SUMMARY_LEN 200

int main() {

  FILE *fp;
  char input[MAX_LINE_LEN], summary[MAX_SUMMARY_LEN];
  int score[MAX_LINE_LEN], sum_score = 0, len, summary_len = 0;

  fp = fopen("input.txt", "r"); // Assuming the text to be summarized is in a file called "input.txt"

  if (fp == NULL) {
    fprintf(stderr, "Error opening input file\n");
    exit(1);
  }

  while (fgets(input, MAX_LINE_LEN, fp) != NULL) {

    len = strlen(input);

    for (int i = 0; i < len; i++) {
      if (input[i] == '.') {
        score[i] = 1;
      }
      else if (input[i] == ',' || input[i] == ':' || input[i] == ';') {
        score[i] = 0;
      }
      else {
        score[i] = -1;
      }
    }

    int start = 0, end = len;

    for (int i = 0; i < len; i++) {
      if (score[i] > 0) {
        start = i + 1;
        for (int j = i + 1; j < len; j++) {
          if (score[j] >= 0) {
            end = j;
            break;
          }
        }
        int sentence_score = 0;
        for (int j = start; j < end; j++) {
          if (score[j] >= 0) {
            sentence_score += score[j];
          }
        }
        sum_score += sentence_score;
        if (summary_len < MAX_SUMMARY_LEN) {
          strncat(summary, input + start, end - start);
          summary_len += end - start;
          strncat(summary, " ", 1);
          summary_len++;
        }
      }
    }

  }

  fclose(fp);

  printf("Summary:\n%s\n", summary);

  return 0;
}