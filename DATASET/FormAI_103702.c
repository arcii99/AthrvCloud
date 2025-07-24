//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 128
#define MAX_FIELDS_PER_LINE 20

typedef struct csv_reader {
    FILE *fp;
    char *line;
    char *field[MAX_FIELDS_PER_LINE];
    int num_fields;
} csv_reader;

// Constructor
csv_reader* csv_reader_create(char *filename) {
    csv_reader *reader = malloc(sizeof(csv_reader));
    reader->fp = fopen(filename, "r");
    if (!reader->fp) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }
    reader->line = malloc(sizeof(char) * MAX_LINE_LENGTH);
    memset(reader->field, 0, sizeof(char*) * MAX_FIELDS_PER_LINE);
    reader->num_fields = 0;
    return reader;
}

// Destructor
void csv_reader_destroy(csv_reader *reader) {
    fclose(reader->fp);
    free(reader->line);
    free(reader);
}

// Split line into fields
void csv_reader_split_line(csv_reader *reader) {
    char *delimiter = ",";
    char *token = strtok(reader->line, delimiter);
    reader->num_fields = 0;
    while (token != NULL && reader->num_fields < MAX_FIELDS_PER_LINE) {
        reader->field[reader->num_fields++] = token;
        token = strtok(NULL, delimiter);
    }
}

// Parse field as integer
int csv_reader_parse_int(char *field) {
    int value = 0;
    char *p = field;
    while (*p != '\0') {
        if (isdigit(*p)) {
            value = value * 10 + (*p - '0');
        } else {
            printf("Invalid integer: %s\n", field);
            return -1;
        }
        p++;
    }
    return value;
}

// Read next line
int csv_reader_read_line(csv_reader *reader) {
    if (!fgets(reader->line, MAX_LINE_LENGTH, reader->fp)) {
        return 0;
    }
    reader->line[strcspn(reader->line, "\r\n")] = '\0'; // Remove newline characters
    csv_reader_split_line(reader);
    return 1;
}

int main() {
    csv_reader *reader = csv_reader_create("example.csv");
    if (!reader) {
        return 1;
    }
    while (csv_reader_read_line(reader)) {
        for (int i = 0; i < reader->num_fields; i++) {
            int value = csv_reader_parse_int(reader->field[i]);
            if (value != -1) {
                printf("%d ", value);
            }
        }
        printf("\n");
    }
    csv_reader_destroy(reader);
    return 0;
}