//FormAI DATASET v1.0 Category: Log analysis ; Style: grateful
#include <stdio.h>

int main() {
  FILE *log_file;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  log_file = fopen("log.txt", "r");

  if (log_file == NULL) {
    printf("Could not open log file!\n");
    return 1;
  }

  while ((read = getline(&line, &len, log_file)) != -1) {
    /* code to analyze each line goes here */
  }

  fclose(log_file);
  if (line){
    free(line);
  }

  return 0;
}