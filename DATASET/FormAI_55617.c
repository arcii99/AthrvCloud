//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LEN 100

int main() {
  FILE *fp;
  char line[MAX_LEN];
  char *keywords[] = {"hack", "crack", "exploit", "spoof"};
  int i, j;
  int match_count[MAX_LINES] = {0};
  int lines_matched = 0;

  fp = fopen("log.txt", "r");
  
  if (fp == NULL){
    printf("Unable to open file");
    return 1;
  }

  i = 0;
  while (fgets(line, MAX_LEN, fp)) {
    for (j = 0; j < 4; j++) {
      if (strstr(line, keywords[j]) != NULL) {
        match_count[i]++;
        lines_matched++;
      }
    }
    i++;
  }

  printf("Number of lines matched: %d\n", lines_matched);
  for (i = 0; i < MAX_LINES; i++) {
    if (match_count[i] > 0) {
      printf("Line %d match count: %d\n", i+1, match_count[i]);
    }
  }

  fclose(fp);
  
  return 0;
}