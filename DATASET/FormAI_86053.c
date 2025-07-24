//FormAI DATASET v1.0 Category: Log analysis ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("ERROR: Usage: log_analysis [filename]\n");
    exit(EXIT_FAILURE);
  }

  FILE *fptr;
  char buffer[BUFFER_SIZE];
  char *token;
  char *search = "error";
  int line_num = 1;

  fptr = fopen(argv[1], "r");
  if (fptr == NULL) {
    printf("ERROR: File not found.\n");
    exit(EXIT_FAILURE);
  }

  printf("Log analysis for file: %s\n", argv[1]);
  printf("---------------------------------\n");

  while (fgets(buffer, BUFFER_SIZE, fptr)) {
    token = strtok(buffer, " \n");
    while (token != NULL) {
      if (strstr(token, search) != NULL) {
        printf("Line %d: %s", line_num, buffer);
        break;
      }
      token = strtok(NULL, " \n");
    }
    line_num++;
  }

  printf("---------------------------------\n");
  printf("Analysis complete.\n");

  fclose(fptr);
  return 0;
}