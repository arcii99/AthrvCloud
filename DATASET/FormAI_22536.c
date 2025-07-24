//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_LINE_LEN 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 1;
    }

    char line[MAX_LINE_LEN];
    char *field;
    int row = 0;
    int col = 0;
    char *data[MAX_ROWS][MAX_COLS];

    while (fgets(line, MAX_LINE_LEN, fp) != NULL && row < MAX_ROWS) {
        col = 0;
        field = strtok(line, ",");
        while (field != NULL && col < MAX_COLS) {
            // Remove the new line character if present
            int field_len = strlen(field);
            if (field[field_len-1] == '\n') {
                field[field_len-1] = '\0';
            }
            data[row][col] = field;
            col++;
            field = strtok(NULL, ",");
        }
        row++;
    }

    fclose(fp);

    // Output the data
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}