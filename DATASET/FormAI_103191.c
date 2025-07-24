//FormAI DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int i = 0;

  if (argc != 2) {
    printf("Usage: %s <logfile>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Failed to open file: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  printf("Number of lines in logfile: ");

  while ((read = getline(&line, &len, fp)) != -1) {
    if (strstr(line, "ERROR")) {
      printf("\nError found on line %d:\n%s", i, line);
    }
    i++;
  }

  printf("%d\n", i);

  free(line);
  fclose(fp);
  exit(EXIT_SUCCESS);
}