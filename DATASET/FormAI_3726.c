//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct row {
    char** values; // array of strings
    int len; // number of columns
} Row;

typedef struct csv {
    Row* rows; // array of rows
    int len; // number of rows
} CSV;

void read_csv(const char* filename, CSV* csv) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file '%s'\n", filename);
        exit(1);
    }

    int num_rows = 0;
    int max_cols = 0;

    char buffer[1024];
    while (fgets(buffer, 1024, file)) { // read file line by line
        num_rows++; // increase the number of rows

        char* token = strtok(buffer, ",\n");
        int num_cols = 1;

        while (token != NULL) {
            num_cols++; // increase the number of columns
            token = strtok(NULL, ",\n");
        }

        if (num_cols > max_cols) {
            max_cols = num_cols;
        }
    }

    csv->rows = malloc(num_rows * sizeof(Row)); // allocate memory for rows
    csv->len = num_rows;

    fseek(file, 0, SEEK_SET);

    int count = 0;
    while (fgets(buffer, 1024, file)) {
        Row row;
        row.values = malloc(max_cols * sizeof(char*)); // allocate memory for values
        row.len = 0;

        char* token = strtok(buffer, ",\n");
        while (token != NULL) {
            char* value = malloc(strlen(token) + 1); // allocate memory for value
            strcpy(value, token);
            row.values[row.len++] = value;
            token = strtok(NULL, ",\n");
        }

        csv->rows[count++] = row;
    }

    fclose(file);
}

void free_csv(CSV* csv) {
    for (int i = 0; i < csv->len; i++) {
        for (int j = 0; j < csv->rows[i].len; j++) {
            free(csv->rows[i].values[j]); // free memory for values
        }
        free(csv->rows[i].values); // free memory for array of values
    }
    free(csv->rows); // free memory for array of rows
    csv->len = 0;
}

int main() {
    CSV csv;
    read_csv("example.csv", &csv);

    for (int i = 0; i < csv.len; i++) {
        for (int j = 0; j < csv.rows[i].len; j++) {
            printf("%s ", csv.rows[i].values[j]); // print values
        }
        printf("\n");
    }

    free_csv(&csv);

    return 0;
}