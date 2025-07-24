//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LEN 100 // maximum length of a field in the CSV file
#define MAX_LINE_LEN 1000 // maximum length of a line in the CSV file

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s filename.csv\n", argv[0]);
    exit(1);
  }

  FILE *fp = fopen(argv[1], "r");
  if (!fp) {
    printf("Error opening file %s\n", argv[1]);
    exit(1);
  }

  char line[MAX_LINE_LEN]; // buffer for reading each line of the CSV file
  char *field; // pointer to the current field in the line
  char delimiter[] = ","; // the CSV delimiter
  int row = 0; // the current row of the CSV file

  while (fgets(line, MAX_LINE_LEN, fp)) { // read each line of the CSV file
    row++; // increment the row counter

    // check if the line is empty or a comment
    if (line[0] == '\n' || line[0] == '#') {
      continue;
    }

    int field_count = 0; // the number of fields in the line
    char *line_ptr = line; // pointer to the beginning of the line
    while ((field = strtok(line_ptr, delimiter)) != NULL) { // split the line by the CSV delimiter
      field_count++; // increment the field counter
      line_ptr = NULL; // set the pointer to NULL to continue parsing from the last token
      if (strlen(field) > MAX_FIELD_LEN) { // check if the field length is too long
        printf("Error: field length exceeds maximum allowed on row %d, field %d\n", row, field_count);
        exit(1);
      }
      printf("Field %d in row %d: \"%s\"\n", field_count, row, field);
    }

    if (field_count == 0) { // check if the line is empty after parsing
      printf("Warning: empty line on row %d\n", row);
    }
  }

  fclose(fp);

  return 0;
}