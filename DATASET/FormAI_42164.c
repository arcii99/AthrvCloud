//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 128

typedef struct csv {
    int rows;
    int cols;
    char*** data;
} csv_t;

int count_char(char* line, char chr) {
    int count = 0;
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == chr) {
            count++;
        }
    }
    return count;
}

char* get_field(char* line, int index, char delimiter) {
    char* field = (char*)malloc(MAX_FIELD_SIZE * sizeof(char));
    char* token = strtok(line, &delimiter);
    int current_index = 0;

    while (token != NULL) {
        if (current_index == index) {
            strcpy(field, token);
            return field;
        }

        current_index++;
        token = strtok(NULL, &delimiter);
    }

    return "";
}

csv_t* read_csv_file(char* file_path, char delimiter) {
    FILE* file = fopen(file_path, "r");

    if (!file) {
        printf("Failed to open file: %s\n", file_path);
        return NULL;
    }

    char line[MAX_LINE_SIZE];
    int row_count = 0;
    int col_count;

    while (fgets(line, MAX_LINE_SIZE, file)) {
        if (row_count == 0) {
            col_count = count_char(line, delimiter) + 1;
        }

        row_count++;
    }

    rewind(file);

    csv_t* csv = (csv_t*)malloc(sizeof(csv_t));
    csv->rows = row_count;
    csv->cols = col_count;
    csv->data = (char***)malloc(row_count * sizeof(char**));

    int row_index = 0;

    while (fgets(line, MAX_LINE_SIZE, file)) {
        csv->data[row_index] = (char**)malloc(col_count * sizeof(char*));

        for (int i = 0; i < col_count; i++) {
            csv->data[row_index][i] = (char*)malloc(MAX_FIELD_SIZE * sizeof(char));
            strcpy(csv->data[row_index][i], get_field(line, i, delimiter));
        }

        row_index++;
    }

    fclose(file);

    return csv;
}

void print_csv(csv_t* csv) {
    if (!csv) {
        printf("CSV file is empty.\n");
        return;
    }

    printf("Rows = %d, Cols = %d\n", csv->rows, csv->cols);

    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s\t", csv->data[i][j]);
        }

        printf("\n");
    }
}

int main() {
    csv_t* csv = read_csv_file("example.csv", ',');
    print_csv(csv);

    return 0;
}