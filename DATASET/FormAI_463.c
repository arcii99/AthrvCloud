//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: csv_reader <file_name>\n");
    return -1;
  }

  FILE *fp = fopen(argv[1], "r");

  if (fp == NULL) {
    printf("Error opening file!\n");
    return -1;
  }

  char line[MAX_LINE_SIZE];

  while (fgets(line, MAX_LINE_SIZE, fp)) {
    char *token = strtok(line, ",");
    while (token) {
      printf("%s\t", token);
      token = strtok(NULL, ",");
    }
    printf("\n");
  }

  fclose(fp);

  return 0;
}