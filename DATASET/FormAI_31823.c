//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_SIZE 1024
#define MAX_FIELDS 128

typedef struct {
    char* fields[MAX_FIELDS];
    int count;
} CsvRow;

typedef struct {
    char* filename;
    FILE* file;
    char* buffer;
    size_t buffer_size;
    char* pos;
    char* end;
} CsvReader;

CsvReader* csv_reader_new(const char* filename, const char* sep) {
    CsvReader* reader = (CsvReader*) malloc(sizeof(CsvReader));
    reader->filename = strdup(filename);
    reader->file = fopen(filename, "rb");
    reader->buffer_size = 4096;
    reader->buffer = (char*) malloc(reader->buffer_size);
    reader->pos = reader->buffer;
    reader->end = reader->buffer;
    return reader;
}

void csv_reader_free(CsvReader* reader) {
    fclose(reader->file);
    free(reader->filename);
    free(reader->buffer);
    free(reader);
}

char* csv_reader_next_line(CsvReader* reader) {
    char* start = reader->pos;
    while (reader->pos < reader->end && *reader->pos != '\n') {
        reader->pos++;
    }
    if (reader->pos == reader->end) {
        if (feof(reader->file)) {
            return NULL;
        }
        size_t size = reader->end - start;
        memmove(reader->buffer, start, size);
        reader->pos = reader->buffer;
        reader->end = reader->buffer + size;
        size_t count = fread(reader->end, 1, reader->buffer_size - size, reader->file);
        reader->end += count;
        return csv_reader_next_line(reader);
    }
    *reader->pos = '\0';
    reader->pos++;
    return start;
}

CsvRow* csv_reader_parse_row(const char* line, const char* sep) {
    CsvRow* row = (CsvRow*) malloc(sizeof(CsvRow));
    row->count = 0;
    char* start = (char*) line;
    while (*start) {
        if (row->count >= MAX_FIELDS) {
            fprintf(stderr, "Too many fields in line %d\n", row->count);
            free(row);
            return NULL;
        }
        row->fields[row->count] = start;
        row->count++;
        start = strchr(start, *sep);
        if (!start) {
            break;
        }
        *start++ = '\0';
    }
    return row;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: csv_reader <filename>\n");
        return EXIT_FAILURE;
    }
    CsvReader* reader = csv_reader_new(argv[1], ",");
    if (!reader) {
        fprintf(stderr, "Failed to open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    char* line;
    while ((line = csv_reader_next_line(reader)) != NULL) {
        CsvRow* row = csv_reader_parse_row(line, ",");
        if (!row) {
            fprintf(stderr, "Failed to parse line %s\n", line);
            continue;
        }
        printf("Row: ");
        for (int i = 0; i < row->count; i++) {
            printf("%s ", row->fields[i]);
        }
        printf("\n");
        free(row);
    }
    csv_reader_free(reader);
    return EXIT_SUCCESS;
}