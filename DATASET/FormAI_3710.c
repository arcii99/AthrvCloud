//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: cheerful
#include <stdio.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_ROWS 50
#define MAX_LINE_LENGTH 100

int main() {
    char filename[] = "students.csv";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Oops! Couldn't open file %s", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *tokens[MAX_COLS];

    int row_count = 0, col_count = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) && row_count < MAX_ROWS) {
        col_count = 0;
        char *token = strtok(line, ",");
        while (token && col_count < MAX_COLS) {
            tokens[col_count++] = token;
            token = strtok(NULL, ",");
        }
        row_count++;

        printf("----- Student Record -----\n");
        printf("Name:\t\t%s\n", tokens[0]);
        printf("Age:\t\t%s\n", tokens[1]);
        printf("City:\t\t%s\n", tokens[2]);
        printf("Grade:\t\t%s\n", tokens[3]);
        printf("\n");
    }

    fclose(file);
    printf("Reading complete!\n");

    return 0;
}