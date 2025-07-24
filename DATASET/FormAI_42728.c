//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

typedef struct {
    int num_columns;
    char *column_headers[MAX_COLUMNS];
    char *column_values[MAX_COLUMNS];
} csv_row;

void tokenize_line(char *line, char *delim, char **tokens, int max_tokens) {
    int i = 0;
    tokens[i] = strtok(line, delim);
    while (tokens[i] != NULL && i < max_tokens) {
        tokens[++i] = strtok(NULL, delim);
    }
}

void parse_line(char *line, csv_row *row, char *delim) {
    char *tokens[MAX_COLUMNS];
    tokenize_line(line, delim, tokens, MAX_COLUMNS);
    row->num_columns = 0;
    for (int i = 0; i < MAX_COLUMNS && tokens[i] != NULL; i++) {
        if (i == 0) {
            row->column_values[row->num_columns] = tokens[i];
        } else {
            row->column_headers[row->num_columns - 1] = tokens[i];
            row->column_values[row->num_columns] = NULL;
        }
        row->num_columns++;
    }
}

void print_row(csv_row *row) {
    printf("CSV row with %d columns:\n", row->num_columns);
    for (int i = 0; i < row->num_columns; i++) {
        if (row->column_headers[i] != NULL) {
            printf("\t%s: %s\n", row->column_headers[i], row->column_values[i]);
        } else {
            printf("\t%s\n", row->column_values[i]);
        }
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char delim[] = ",";
    csv_row row;

    // Read and print header row
    fgets(line, MAX_LINE_LENGTH, fp);
    parse_line(line, &row, delim);
    print_row(&row);

    // Read and print all other rows
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        parse_line(line, &row, delim);
        print_row(&row);
    }

    fclose(fp);

    return 0;
}