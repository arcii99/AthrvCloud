//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 500
#define MAX_FIELDS 50

char* field[MAX_FIELDS];
int field_count = 0;

void display_csv(char** data, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%s\t", data[i * columns + j]);
        }
        printf("\n");
    }
}

void read_csv(const char* file_name, char** data, int* rows, int* columns, const char* delimiter) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        char* token = strtok(line, delimiter);
        while (token != NULL) {
            field[field_count++] = token;
            token = strtok(NULL, delimiter);
        }
        int column_count = 0;
        for (int i = 0; i < field_count; i++) {
            data[*rows * (*columns) + column_count++] = field[i];
        }
        (*rows)++;
        field_count = 0;
    }
    (*columns) = field_count;
    fclose(file);
}

int main() {
    printf("CSV Reader Program\n\n");

    char* data[MAX_FIELDS * MAX_LINE_SIZE];
    int rows = 0;
    int columns = 0;

    read_csv("example.csv", data, &rows, &columns, ",");

    printf("Number of rows: %d\n", rows);
    printf("Number of columns: %d\n", columns);
    display_csv(data, rows, columns);

    return 0;
}