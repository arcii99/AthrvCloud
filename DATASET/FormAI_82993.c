//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100 // Maximum size of each line in CSV
#define MAX_FIELDS 10 // Maximum number of fields in CSV
#define MAX_FIELD_SIZE 20 // Maximum size of each field

int count_fields(char line[]) {
  int count = 0;
  char* token = strtok(line, ",");
  while (token != NULL && count < MAX_FIELDS) {
    count++;
    token = strtok(NULL, ",");
  }
  return count;
}

void parse_csv(char csv_file[]) {
  FILE* file = fopen(csv_file, "r");
  if (file == NULL) {
    printf("Error: Could not open file '%s'\n", csv_file);
    exit(1);
  }

  char line[MAX_LINE_SIZE];
  int line_count = 0;
  int field_count = 0;
  char fields[MAX_FIELDS][MAX_FIELD_SIZE];

  printf("Parsing CSV file '%s'\n", csv_file);
  while (fgets(line, MAX_LINE_SIZE, file)) {
    line_count++;

    // Remove newline character from line
    line[strcspn(line, "\n")] = 0;

    // Count number of fields in line
    field_count = count_fields(line);

    // Check if number of fields exceeds maximum
    if (field_count > MAX_FIELDS) {
      printf("Error: Line %d in file '%s' has %d fields (maximum is %d)\n", line_count, csv_file, field_count, MAX_FIELDS);
      exit(1);
    }

    // Copy fields to array
    char* token = strtok(line, ",");
    int i = 0;
    while (token != NULL) {
      if (i >= MAX_FIELDS) {
        printf("Error: Line %d in file '%s' has more than %d fields\n", line_count, csv_file, MAX_FIELDS);
        exit(1);
      }
      strncpy(fields[i], token, MAX_FIELD_SIZE);
      i++;
      token = strtok(NULL, ",");
    }

    // Print fields
    printf("Line %d: ", line_count);
    for (int j = 0; j < field_count; j++) {
      printf("%s, ", fields[j]);
    }
    printf("\n");
  }

  fclose(file);
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Error: No input file specified\n");
    return 1;
  }

  parse_csv(argv[1]);

  return 0;
}