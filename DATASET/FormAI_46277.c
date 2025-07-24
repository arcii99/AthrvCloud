//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct csv_row {
    char **columns;
    int num_columns;
} csv_row;

typedef struct csv_reader {
    FILE *file;
    char *delimiter;
    char *newline;
    int has_header_row;
} csv_reader;

void free_csv_row(csv_row *row) {
    for (int i = 0; i < row->num_columns; i++) {
        free(row->columns[i]);
    }
    free(row->columns);
    free(row);
}

csv_row *parse_csv_line(char *line, char *delimiter) {
    int num_columns = 0;
    char **columns = malloc(sizeof(char*));
    char *column = strtok(line, delimiter);
    while (column != NULL) {
        num_columns++;
        columns = realloc(columns, sizeof(char*) * num_columns);
        columns[num_columns - 1] = strdup(column);
        column = strtok(NULL, delimiter);
    }
    csv_row *row = malloc(sizeof(csv_row));
    row->columns = columns;
    row->num_columns = num_columns;
    return row;
}

csv_reader *create_csv_reader(FILE *file, char *delimiter, char *newline, int has_header_row) {
    csv_reader *reader = malloc(sizeof(csv_reader));
    reader->file = file;
    reader->delimiter = delimiter;
    reader->newline = newline;
    reader->has_header_row = has_header_row;
    return reader;
}

void free_csv_reader(csv_reader *reader) {
    fclose(reader->file);
    free(reader->delimiter);
    free(reader->newline);
    free(reader);
}

csv_row *get_csv_header_row(csv_reader *reader) {
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, reader->file);
    if (reader->newline != NULL) {
        char *newline_found = strstr(line, reader->newline);
        if (newline_found != NULL) {
            newline_found[0] = '\0';
        }
    }
    return parse_csv_line(line, reader->delimiter);
}

csv_row *get_next_csv_row(csv_reader *reader) {
    if (reader->has_header_row) {
        reader->has_header_row = 0;
        return get_csv_header_row(reader);
    }
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, reader->file) == NULL) {
        return NULL;
    }
    if (reader->newline != NULL) {
        char *newline_found = strstr(line, reader->newline);
        if (newline_found != NULL) {
            newline_found[0] = '\0';
        }
    }
    return parse_csv_line(line, reader->delimiter);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <csv_filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        return 1;
    }
    csv_reader *reader = create_csv_reader(file, ",", "\n", 1);
    csv_row *header_row = get_csv_header_row(reader);
    printf("Header row:\n");
    for (int i = 0; i < header_row->num_columns; i++) {
        printf("%s\n", header_row->columns[i]);
    }
    printf("\nData rows:\n");
    csv_row *row = get_next_csv_row(reader);
    while (row != NULL) {
        for (int i = 0; i < row->num_columns; i++) {
            printf("%s ", row->columns[i]);
        }
        printf("\n");
        free_csv_row(row);
        row = get_next_csv_row(reader);
    }
    free_csv_row(header_row);
    free_csv_reader(reader);
    return 0;
}