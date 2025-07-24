//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100 // maximum length of a field in the CSV file

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Usage: %s <csv_file>\n", argv[0]);
    return 1;
  }

  char *filename = argv[1];
  FILE *fp = fopen(filename, "r");
  if(!fp) {
    printf("Error opening file %s\n", filename);
    return 1;
  }

  char line[MAX_LEN];
  while(fgets(line, MAX_LEN, fp)) {
    char *ptr = strtok(line, ",\n"); // tokenize the CSV file by comma or newline
    while(ptr) {
      printf("%s\n", ptr);
      ptr = strtok(NULL, ",\n");
    }
  }

  fclose(fp);
  return 0;
}