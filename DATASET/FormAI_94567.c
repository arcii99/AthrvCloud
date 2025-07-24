//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 50
#define MAX_COL_NAME_LENGTH 50
#define MAX_LINE_LENGTH 1000

struct csv_reader {
    FILE *fp;
    int num_columns;
    char col_names[MAX_COLS][MAX_COL_NAME_LENGTH];
};

void init_csv_reader(struct csv_reader *csv, const char *filename) {
    csv->fp = fopen(filename, "r");
    if (csv->fp == NULL) {
        printf("Error opening file \"%s\"!\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, csv->fp) == NULL) {
        printf("Error reading column names from file \"%s\"!\n", filename);
        exit(1);
    }

    int num_columns = 0;
    char *token = strtok(line, ",");
    while (token != NULL && num_columns < MAX_COLS) {
        strncpy(csv->col_names[num_columns++], token, MAX_COL_NAME_LENGTH);
        token = strtok(NULL, ",");
    }
    csv->num_columns = num_columns;
}

void destroy_csv_reader(struct csv_reader *csv) {
    fclose(csv->fp);
}

void print_columns(struct csv_reader *csv) {
    for (int i = 0; i < csv->num_columns; i++) {
        printf("%s%s", csv->col_names[i], (i == csv->num_columns - 1) ? "\n" : ",");
    }
}

void print_row(struct csv_reader *csv, const char *row) {
    char *copy = strdup(row);
    char *token = strtok(copy, ",");
    for (int i = 0; i < csv->num_columns; i++) {
        printf("%s%s", token, (i == csv->num_columns - 1) ? "\n" : ",");
        token = strtok(NULL, ",");
    }
    free(copy);
}

void print_csv(struct csv_reader *csv) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, csv->fp) != NULL) {
        print_row(csv, line);
    }
}

int main() {
    struct csv_reader csv;
    init_csv_reader(&csv, "example.csv");
    print_columns(&csv);
    print_csv(&csv);
    destroy_csv_reader(&csv);
    return 0;
}