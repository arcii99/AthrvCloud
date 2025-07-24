//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_CSV_LEN 1000

typedef struct CSVRow {
    char** fields; 
    int num_fields; 
} CSVRow;

typedef struct CSVReader {
    FILE* file; 
    CSVRow* header; 
    int max_rows; 
    int cur_row; 
    CSVRow** rows; 
} CSVReader;

CSVReader* csv_reader_new(const char* filename, int max_rows) {
    CSVReader* reader = (CSVReader*)malloc(sizeof(CSVReader));
    reader->file = fopen(filename, "r");
    reader->max_rows = max_rows;
    reader->cur_row = 0;
    
    // read header row
    char line[MAX_CSV_LEN];
    if (fgets(line, MAX_CSV_LEN, reader->file) == NULL) {
        printf("Error: could not read header row.\n");
        return NULL;
    }
    int num_fields = 0;
    char* field = strtok(line, ",");
    reader->header = (CSVRow*)malloc(sizeof(CSVRow));
    reader->header->num_fields = 0;
    reader->header->fields = (char**)malloc(sizeof(char*) * reader->max_rows);
    while (field != NULL) {
        reader->header->fields[num_fields] = strdup(field);
        num_fields++;
        field = strtok(NULL, ",");
    }
    reader->header->num_fields = num_fields;
    
    // read data rows
    reader->rows = (CSVRow**)malloc(sizeof(CSVRow*) * reader->max_rows);
    while (fgets(line, MAX_CSV_LEN, reader->file) != NULL && reader->cur_row < max_rows) {
        CSVRow* row = (CSVRow*)malloc(sizeof(CSVRow));
        row->num_fields = 0;
        row->fields = (char**)malloc(sizeof(char*) * reader->header->num_fields);
        field = strtok(line, ",");
        int i = 0;
        while (field != NULL) {
            row->fields[i] = strdup(field);
            i++;
            field = strtok(NULL, ",");
        }
        row->num_fields = i;
        reader->rows[reader->cur_row] = row;
        reader->cur_row++;
    }
    return reader;
}

void csv_reader_free(CSVReader* reader) {
    fclose(reader->file);
    for (int i = 0; i < reader->cur_row; i++) {
        CSVRow* row = reader->rows[i];
        for (int j = 0; j < row->num_fields; j++) {
            free(row->fields[j]);
        }
        free(row->fields);
        free(row);
    }
    free(reader->rows);
    for (int i = 0; i < reader->header->num_fields; i++) {
        free(reader->header->fields[i]);
    }
    free(reader->header->fields);
    free(reader->header);
    free(reader);
}

void csv_row_print(CSVRow* row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s", row->fields[i]);
        if (i < row->num_fields - 1) printf(",");
    }
    printf("\n");
}

void csv_reader_print(CSVReader* reader) {
    csv_row_print(reader->header);
    for (int i = 0; i < reader->cur_row; i++) {
        csv_row_print(reader->rows[i]);
    }
}

int main() {
    CSVReader* reader = csv_reader_new("example.csv", 100);
    if (reader == NULL) return 1;
    csv_reader_print(reader);
    csv_reader_free(reader);
    return 0;
}