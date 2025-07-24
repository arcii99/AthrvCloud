//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *filename = NULL;
    FILE *file = NULL;
    char filebuffer[MAX_BUFFER_SIZE];
    char *field = NULL;
    int row = 0, col = 0;
    int fields_per_row = 0;

    if (argc < 2) {
        printf("Error: Please specify a path to a CSV file.\n");
        return 1;
    }

    filename = argv[1];
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    while (fgets(filebuffer, MAX_BUFFER_SIZE, file) != NULL) {
        // Parse CSV row
        row++;

        field = strtok(filebuffer, ",");
        col = 0;
        fields_per_row = 0;

        while (field != NULL) {
            col++;
            fields_per_row++;
            printf("%s", field);
            field = strtok(NULL, ",");
        }

        // If there were less fields in this row than in previous rows, pad the row with empty fields
        while (col < fields_per_row) {
            col++;
            printf(",");
        }

        printf("\n");
    }

    fclose(file);
    return 0;
}