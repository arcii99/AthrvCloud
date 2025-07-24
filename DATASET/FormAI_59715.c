//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 1000
#define MAX_COLUMN_NAME_LENGTH 50
#define MAX_RECORD_LENGTH 1000

/* Function to trim leading and trailing whitespace */
char *trim(char * str) {
  char * end = str + strlen(str) - 1;
  while (end > str && isspace(*end)) {
    end--;
  }
  *(end + 1) = '\0';
  while (*str && isspace(*str)) {
    str++;
  }
  return str;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: csv_reader <filename>\n");
        return 1;
    }

    char * filename = argv[1];
    FILE * file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 1;
    }

    char column_names[MAX_COLUMNS][MAX_COLUMN_NAME_LENGTH];
    int num_columns = 0;
    char line[MAX_RECORD_LENGTH];
    fgets(line, MAX_RECORD_LENGTH, file);

    char *token = strtok(line, ",");
    while (token != NULL && num_columns < MAX_COLUMNS) {
        strncpy(column_names[num_columns], trim(token), MAX_COLUMN_NAME_LENGTH);
        num_columns++;
        token = strtok(NULL, ",");
    }

    printf("Found %d columns:\n", num_columns);
    for (int i = 0; i < num_columns; i++) {
        printf("%s\n", column_names[i]);
    }

    printf("Parsing records...\n");
    while (fgets(line, MAX_RECORD_LENGTH, file)) {
        printf("Record:\n");

        char *record[MAX_COLUMNS];
        int record_index = 0;

        token = strtok(line, ",");
        while (token != NULL && record_index < num_columns) {
            record[record_index] = trim(token);
            printf("%s: %s\n", column_names[record_index], record[record_index]);
            record_index++;
            token = strtok(NULL, ",");
        }
    }

    fclose(file);
    return 0;
}