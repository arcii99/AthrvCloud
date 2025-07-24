//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char filename[100];
  printf("Enter the name of the file to read: ");
  scanf("%s", filename);

  FILE* file = fopen(filename, "r");

  if(file == NULL) {
    printf("Error opening file %s\n", filename);
    exit(0);
  }

  char field[100];
  char* fields[100];
  int num_fields = 0;

  char line[1000];
  char* tokens;
  int row_count = 0;

  printf("\nReading contents of file %s\n", filename);

  while(fgets(line, 1000, file) != NULL) {
    row_count++;
    int i = 0;
    tokens = strtok(line, ",");
    while(tokens != NULL) {
      strcpy(field, tokens);
      fields[i++] = field;
      tokens = strtok(NULL, ",");
    }
    num_fields = i;
    printf("\nRow %d:\n", row_count);
    for(int j=0; j<num_fields; j++) {
      printf("Field %d: %s\n", j+1, fields[j]);
    }
  }

  printf("\nTotal rows read from file: %d\n", row_count);

  fclose(file);

  return 0;
}