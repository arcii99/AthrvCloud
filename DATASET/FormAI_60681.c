//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLUMNS 10

int main(int argc, char **argv) {

    FILE *csv_file;
    char buffer[MAX_LINE_LENGTH];
    char *tokens[MAX_COLUMNS];
    int num_columns;

    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    csv_file = fopen(argv[1], "r");
    if (csv_file == NULL) {
        printf("Error: Cannot open %s\n", argv[1]);
        return 1;
    }

    while (fgets(buffer, MAX_LINE_LENGTH, csv_file)) {

        num_columns = parse_csv_line(buffer, tokens, MAX_COLUMNS);

        for (int i = 0; i < num_columns; i++) {
            printf("%s  ", tokens[i]);
        }
        printf("\n");
    }

    fclose(csv_file);
    return 0;
}

int parse_csv_line(char *line, char **tokens, int max_columns) {

    int num_columns = 0;

    char *token = strtok(line, ",");
    while (token != NULL && num_columns < max_columns) {
        tokens[num_columns++] = token;
        token = strtok(NULL, ",");
    }

    return num_columns;
}