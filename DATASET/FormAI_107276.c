//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_LINE_LENGTH 1000

// CSV reader example program
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: csvreader <csv_file>\n");
        exit(1);
    }

    FILE *csv_file = fopen(argv[1], "r");
    if (!csv_file) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char *field[MAX_COLS];

    while (fgets(line, MAX_LINE_LENGTH, csv_file)) {
        int num_fields = 0;
        char *token = strtok(line, ",");
        while (token && num_fields < MAX_COLS) {
            field[num_fields++] = strdup(token);
            token = strtok(NULL, ",");
        }

        for (int i = 0; i < num_fields; i++) {
            printf("%s", field[i]);
            if (i < num_fields - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    fclose(csv_file);
    return 0;
}