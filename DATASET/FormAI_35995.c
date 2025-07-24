//FormAI DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {

  if(argc < 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(argv[1], "r");

  if(fp == NULL) {
    fprintf(stderr, "Error Opening File: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while((read = getline(&line, &len, fp)) != -1) {
    if(strlen(line) > 80) {
      fprintf(stderr, "Error: Line Too Long!\n");
      fclose(fp);
      if(line) free(line);
      exit(EXIT_FAILURE);
    }
    printf("Line Read: %s", line);
  }

  if(ferror(fp)) {
    fprintf(stderr, "Error Reading File: %s\n", strerror(errno));
    fclose(fp);
    if(line) free(line);
    exit(EXIT_FAILURE);
  }

  fclose(fp);
  if(line) free(line);
  return 0;
}