//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Row {
    char **columns; // array of strings representing each column in the row
    int num_columns; // number of columns in the row
} Row;

typedef struct CSVReader {
    FILE *file;
    char *delim; // delimiter used in CSV file
    int has_header; // whether or not CSV file has a header row
    Row header_row; // header row of CSV file; only valid if has_header is true
    int num_rows; // number of rows in CSV file (including header if has_header is true)
    Row *rows; // array of Row struct representing each row in the CSV file
} CSVReader;

/**
 * Splits a string into tokens based on a delimiter
 * Returns an array of strings
 */
char **split(const char *str, const char *delim, int *num_tokens) {
    char *copy, *token, **tokens;
    int i;

    // make a copy of the string since strtok modifies the original string
    copy = strdup(str);

    // count the number of tokens
    for (i = 0, token = strtok(copy, delim); token; token = strtok(NULL, delim), i++);
    *num_tokens = i;

    // allocate memory for the array of tokens
    tokens = (char **)malloc(*num_tokens * sizeof(char *));
    if (!tokens) {
        perror("malloc failed");
        exit(1);
    }

    // split the string and populate the array of tokens
    copy = strdup(str); // need to make a fresh copy since strtok modifies the string
    for (i = 0, token = strtok(copy, delim); token; token = strtok(NULL, delim), i++) {
        tokens[i] = strdup(token);
    }

    return tokens;
}

/**
 * Reads a row from a CSV file
 * Returns a Row struct and sets num_columns to the number of columns in the row
 */
Row read_row(FILE *file, const char *delim, int *num_columns) {
    char *line, **columns;
    size_t len = 0;
    ssize_t read;
    int i;

    // read a line from the CSV file into a buffer
    if ((read = getline(&line, &len, file)) == -1) {
        perror("getline failed");
        exit(1);
    }

    // split the line into tokens based on the delimiter
    columns = split(line, delim, num_columns);

    // allocate memory for the Row struct
    Row row;
    row.num_columns = *num_columns;
    row.columns = (char **)malloc(row.num_columns * sizeof(char *));
    if (!row.columns) {
        perror("malloc failed");
        exit(1);
    }

    // copy each token into the corresponding column in the Row struct
    for (i = 0; i < row.num_columns; i++) {
        row.columns[i] = strdup(columns[i]);
    }

    free(line);
    free(columns);
    return row;
}

/**
 * Initializes a CSVReader struct based on a CSV file and delimiter
 */
CSVReader csv_reader_init(const char *filename, const char *delim, int has_header) {
    CSVReader csv_reader;
    csv_reader.file = fopen(filename, "r");
    if (!csv_reader.file) {
        perror("fopen failed");
        exit(1);
    }
    csv_reader.delim = strdup(delim);
    csv_reader.has_header = has_header;
    csv_reader.num_rows = 0;
    csv_reader.header_row.num_columns = 0;
    csv_reader.rows = NULL;

    // read header row if CSV file has a header
    if (csv_reader.has_header) {
        csv_reader.header_row = read_row(csv_reader.file, csv_reader.delim, &csv_reader.header_row.num_columns);
        csv_reader.num_rows++;
    }

    // read each row in the CSV file
    while (!feof(csv_reader.file)) {
        csv_reader.rows = (Row *)realloc(csv_reader.rows, (csv_reader.num_rows + 1) * sizeof(Row));
        csv_reader.rows[csv_reader.num_rows] = read_row(csv_reader.file, csv_reader.delim, &csv_reader.rows[csv_reader.num_rows].num_columns);
        csv_reader.num_rows++;
    }

    return csv_reader;
}

/**
 * Prints a Row struct
 */
void print_row(Row row) {
    int i;
    for (i = 0; i < row.num_columns; i++) {
        printf("%s", row.columns[i]);
        if (i < row.num_columns - 1) {
            printf(",");
        }
    }
    printf("\n");
}

/**
 * Prints a CSVReader struct
 */
void print_csv_reader(CSVReader csv_reader) {
    int i;
    if (csv_reader.has_header) {
        print_row(csv_reader.header_row);
    }
    for (i = 0; i < csv_reader.num_rows - csv_reader.has_header; i++) {
        print_row(csv_reader.rows[i]);
    }
}

/**
 * Frees memory allocated by a Row struct
 */
void free_row(Row row) {
    int i;
    for (i = 0; i < row.num_columns; i++) {
        free(row.columns[i]);
    }
    free(row.columns);
}

/**
 * Frees memory allocated by a CSVReader struct
 */
void free_csv_reader(CSVReader csv_reader) {
    int i;
    for (i = 0; i < csv_reader.num_rows; i++) {
        free_row(csv_reader.rows[i]);
    }
    free(csv_reader.rows);
    free(csv_reader.delim);
    if (csv_reader.has_header) {
        free_row(csv_reader.header_row);
    }
    fclose(csv_reader.file);
}

int main() {
    CSVReader csv_reader = csv_reader_init("data.csv", ",", 1);
    print_csv_reader(csv_reader);
    free_csv_reader(csv_reader);
    return 0;
}