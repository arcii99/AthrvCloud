//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ROWS 1000
#define MAX_CHARS_PER_LINE 1000
#define DELIMITER ","

typedef struct {
    char *data[MAX_CHARS_PER_LINE];
} Row;

int main() {
    FILE *file_pointer;
    char *filename = "sample.csv";
    char line[MAX_CHARS_PER_LINE];
    Row rows[MAX_ROWS];
    int row_index = 0, col_index = 0;

    file_pointer = fopen(filename, "r");

    if (file_pointer == NULL) {
        printf("File does not exist.");
        return 1;
    }

    while (fgets(line, MAX_CHARS_PER_LINE, file_pointer) != NULL) {
        Row current_row;
        char *token;

        token = strtok(line, DELIMITER);

        while (token != NULL) {
            current_row.data[col_index] = malloc(strlen(token) + 1);
            strcpy(current_row.data[col_index], token);
            token = strtok(NULL, DELIMITER);
            col_index++;
        }

        rows[row_index++] = current_row;
        col_index = 0;
    }

    fclose(file_pointer);

    for (int i = 0; i < row_index; i++) {
        Row current_row = rows[i];

        for (int j = 0; current_row.data[j] != NULL; j++) {
            printf("%s\t", current_row.data[j]);
            free(current_row.data[j]);
        }

        printf("\n");
    }

    return 0;
}