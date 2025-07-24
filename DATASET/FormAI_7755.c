//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 20
#define MAX_CHARS_PER_COLUMN 50

typedef struct {
    char **columns;
    int num_columns;
} row;

typedef struct {
    row *rows;
    int num_rows;
} csv_data;

void free_csv_data(csv_data *data) {
    for(int i = 0; i < data->num_rows; i++) {
        for(int j = 0; j < data->rows[i].num_columns; j++) {
            free(data->rows[i].columns[j]);
        }
        free(data->rows[i].columns);
    }
    free(data->rows);
}

csv_data read_csv(const char *filename, char delim) {
    csv_data data = {NULL, 0};
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return data;
    }

    char line[MAX_COLUMNS * MAX_CHARS_PER_COLUMN];
    data.rows = malloc(sizeof(row));
    while(fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0';
        data.num_rows++;

        data.rows = realloc(data.rows, sizeof(row) * data.num_rows);
        data.rows[data.num_rows - 1].num_columns = 1;

        data.rows[data.num_rows - 1].columns = malloc(sizeof(char *));
        char *token = strtok(line, &delim);
        while(token != NULL) {
            data.rows[data.num_rows - 1].num_columns++;
            data.rows[data.num_rows - 1].columns = realloc(data.rows[data.num_rows - 1].columns, sizeof(char *) * data.rows[data.num_rows - 1].num_columns);
            data.rows[data.num_rows - 1].columns[data.rows[data.num_rows - 1].num_columns - 2] = strdup(token);
            token = strtok(NULL, &delim);
        }
    }
    fclose(fp);
    return data;
}

int main() {
    csv_data data = read_csv("example.csv", ',');
    for(int i = 0; i < data.num_rows; i++) {
        printf("Row %d: ", i);
        for(int j = 0; j < data.rows[i].num_columns - 1; j++) {
            printf("%s, ", data.rows[i].columns[j]);
        }
        printf("%s\n", data.rows[i].columns[data.rows[i].num_columns - 1]);
    }
    free_csv_data(&data);
    return 0;
}