//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
  FILE *file;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  char filename[] = "data.csv";
  char *token;
  char delimiter[] = ",\n";
  int count = 0;

  file = fopen(filename, "r");
  if(file == NULL) {
    printf("File could not be opened.\n");
    exit(0);
  }

  printf("CSV File Reader\n");
  printf("----------------\n");

  while((read = getline(&line, &len, file)) != -1) {
    if(count == 0) {
      printf("Header Line: %s", line);
    } else {
      printf("\nRecord %d: ", count);
      token = strtok(line, delimiter);
      while(token != NULL) {
        printf("%s, ", token);
        token = strtok(NULL, delimiter);
      }
    }
    count++;
  }

  fclose(file);
  if(line) {
    free(line);
  }
  printf("\nEnd of file reached. %d records read.\n", count - 1);
  return 0;
}