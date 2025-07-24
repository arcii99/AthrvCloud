//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_SIZE 256
#define MAX_FIELDS 100

typedef struct CSVRow {
    int num_fields;
    char fields[MAX_FIELDS][MAX_FIELD_SIZE];
} CSVRow;

int main() {
    FILE *csv_file = fopen("data.csv", "r");
    if (csv_file == NULL) {
        printf("Error: could not open CSV file!\n");
        exit(1);
    }

    // Read CSV header row
    char header_line[MAX_FIELD_SIZE * MAX_FIELDS];
    fgets(header_line, sizeof(header_line), csv_file);

    // Parse header into field names
    char *field_names[MAX_FIELDS];
    char *token = strtok(header_line, ",");
    int num_fields = 0;
    while (token != NULL && num_fields < MAX_FIELDS) {
        field_names[num_fields++] = token;
        token = strtok(NULL, ",");
    }

    // Read CSV data rows
    CSVRow rows[MAX_FIELDS];
    int num_rows = 0;
    char data_line[MAX_FIELD_SIZE * MAX_FIELDS];
    while (fgets(data_line, sizeof(data_line), csv_file) != NULL) {
        CSVRow *row = &rows[num_rows++];
        row->num_fields = 0;
        token = strtok(data_line, ",");
        while (token != NULL && row->num_fields < MAX_FIELDS) {
            strcpy(row->fields[row->num_fields++], token);
            token = strtok(NULL, ",");
        }
    }

    // Print out all rows
    for (int i = 0; i < num_rows; i++) {
        CSVRow *row = &rows[i];
        printf("Row %d:\n", i + 1);
        for (int j = 0; j < row->num_fields; j++) {
            printf("%s: %s\n", field_names[j], row->fields[j]);
        }
        printf("\n");
    }

    fclose(csv_file);
    return 0;
}