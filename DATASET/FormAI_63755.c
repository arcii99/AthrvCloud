//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096

struct CsvRow {
    char **fields;
    int num_fields;
};

typedef struct CsvRow CsvRow;

typedef struct CsvTable {
    CsvRow **rows;
    int num_rows;
} CsvTable;

CsvRow *csv_read_row(char *line) {
    CsvRow *row = malloc(sizeof(CsvRow));
    if (row == NULL) {
        return NULL;
    }

    row->num_fields = 0;
    row->fields = malloc(sizeof(char *));
    if (row->fields == NULL) {
        free(row);
        return NULL;
    }

    char *field = strtok(line, ",");
    while (field) {
        row->fields[row->num_fields++] = strdup(field);
        row->fields = realloc(row->fields, (row->num_fields+1) * sizeof(char *));
        if (row->fields == NULL) {
            free(row);
            return NULL;
        }

        field = strtok(NULL, ",");
    }

    return row;
}

CsvTable *csv_read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    CsvTable *table = malloc(sizeof(CsvTable));
    if (table == NULL) {
        fclose(fp);
        return NULL;
    }

    table->num_rows = 0;
    table->rows = malloc(sizeof(CsvRow *));
    if (table->rows == NULL) {
        fclose(fp);
        free(table);
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        table->rows[table->num_rows++] = csv_read_row(line);
        table->rows = realloc(table->rows, (table->num_rows+1) * sizeof(CsvRow *));
        if (table->rows == NULL) {
            for (int i = 0; i < table->num_rows; i++) {
                free(table->rows[i]);
            }
            free(table);
            fclose(fp);
            return NULL;
        }
    }

    fclose(fp);
    return table;
}

void csv_free_table(CsvTable *table) {
    for (int i = 0; i < table->num_rows; i++) {
        CsvRow *row = table->rows[i];
        for (int j = 0; j < row->num_fields; j++) {
            free(row->fields[j]);
        }
        free(row->fields);
        free(row);
    }
    free(table->rows);
    free(table);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    CsvTable *table = csv_read_file(argv[1]);
    if (table == NULL) {
        fprintf(stderr, "Error reading file\n");
        return 2;
    }

    printf("Num rows: %d\n", table->num_rows);
    for (int i = 0; i < table->num_rows; i++) {
        CsvRow *row = table->rows[i];
        printf("Row %d: %d fields\n", i, row->num_fields);
        for (int j = 0; j < row->num_fields; j++) {
            printf("\tField %d: %s\n", j, row->fields[j]);
        }
    }

    csv_free_table(table);

    return 0;
}