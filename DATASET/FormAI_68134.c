//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_FILE_SIZE 1048576
#define MAX_NUM_ROWS 100
#define MAX_NUM_COLS 10
#define MAX_FIELD_SIZE 100

typedef struct {
    char data[MAX_NUM_ROWS][MAX_NUM_COLS][MAX_FIELD_SIZE];
    int num_rows;
    int num_cols;
} CSVReader;

void init_csv_reader(CSVReader *csv_reader) {
    memset(csv_reader, 0, sizeof(CSVReader));
}

int read_csv_file(const char *filename, CSVReader *csv_reader) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;
    }

    char file_contents[MAX_CSV_FILE_SIZE];
    int bytes_read = fread(file_contents, 1, MAX_CSV_FILE_SIZE, file);
    if (bytes_read >= MAX_CSV_FILE_SIZE) {
        fclose(file);
        return -2;
    }

    char *token = strtok(file_contents, ",\n");
    int row_index = 0;
    int col_index = 0;
    while (token && row_index < MAX_NUM_ROWS && col_index < MAX_NUM_COLS) {
        strcpy(csv_reader->data[row_index][col_index], token);
        if (++col_index == csv_reader->num_cols) {
            col_index = 0;
            ++row_index;
        }

        token = strtok(NULL, ",\n");
    }

    csv_reader->num_rows = row_index;
    csv_reader->num_cols = col_index;
    fclose(file);

    return 0;
}

void print_csv_reader(CSVReader *csv_reader) {
    for (int row_index = 0; row_index < csv_reader->num_rows; ++row_index) {
        for (int col_index = 0; col_index < csv_reader->num_cols; ++col_index) {
            printf("%s", csv_reader->data[row_index][col_index]);
            if (col_index != csv_reader->num_cols - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    CSVReader csv_reader;
    init_csv_reader(&csv_reader);

    if (read_csv_file(argv[1], &csv_reader) != 0) {
        printf("Failed to read file: %s\n", argv[1]);
        return -2;
    }

    print_csv_reader(&csv_reader);

    return 0;
}