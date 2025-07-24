//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_LINE_LENGTH 1024
#define MAX_CSV_FIELD_LENGTH 128
#define MAX_CSV_FIELDS 10

typedef struct {
    char fields[MAX_CSV_FIELDS][MAX_CSV_FIELD_LENGTH];
    int numFields;
} CsvRow;

typedef struct {
    CsvRow *rows;
    int numRows;
} CsvTable;

CsvRow *csv_read_row(char *line) {
    CsvRow *row = (CsvRow*)malloc(sizeof(CsvRow));
    row->numFields = 0;
    char *nextField = strtok(line, ",");
    while (nextField != NULL) {
        strncpy(row->fields[row->numFields], nextField, MAX_CSV_FIELD_LENGTH-1);
        row->fields[row->numFields][MAX_CSV_FIELD_LENGTH-1] = '\0';
        row->numFields++;
        nextField = strtok(NULL, ",");
    }
    return row;
}

CsvTable *csv_read_table(FILE *csvFile) {
    CsvTable *table = (CsvTable*)malloc(sizeof(CsvTable));
    table->rows = NULL;
    table->numRows = 0;
    char line[MAX_CSV_LINE_LENGTH];
    while (fgets(line, MAX_CSV_LINE_LENGTH, csvFile) != NULL) {
        line[strlen(line)-1] = '\0';
        CsvRow *row = csv_read_row(line);
        if (table->rows == NULL) {
            table->rows = (CsvRow*)malloc(sizeof(CsvRow));
        } else {
            table->rows = (CsvRow*)realloc(table->rows, sizeof(CsvRow) * (table->numRows + 1));
        }
        table->rows[table->numRows++] = *row;
        free(row);
    }
    return table;
}

void csv_print_table(CsvTable *table) {
    for (int i = 0; i < table->numRows; i++) {
        CsvRow row = table->rows[i];
        for (int j = 0; j < row.numFields; j++) {
            printf("%s", row.fields[j]);
            if (j < row.numFields - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

int main() {
    FILE *csvFile = fopen("example_csv_file.csv", "r");
    if (csvFile == NULL) {
        printf("Error opening CSV file\n");
        return 1;
    }
    CsvTable *table = csv_read_table(csvFile);
    fclose(csvFile);
    csv_print_table(table);
    return 0;
}