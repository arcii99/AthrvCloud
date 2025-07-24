//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_COLUMN_NAME_LEN 20
#define MAX_ROW_LEN 1024

typedef struct {
    char name[MAX_COLUMN_NAME_LEN];
    int index;
} Column;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening %s\n", argv[1]);
        return 1;
    }

    char row[MAX_ROW_LEN];
    Column columns[MAX_COLUMNS];
    int num_columns = 0;

    if (fgets(row, MAX_ROW_LEN, file) != NULL) {
        // Parse column names
        char* col_name = strtok(row, ",");
        while (col_name != NULL && num_columns < MAX_COLUMNS) {
            Column column;
            strcpy(column.name, col_name);
            column.index = num_columns;
            columns[num_columns] = column;
            num_columns++;

            col_name = strtok(NULL, ",");
        }
    }

    // Print column names
    for (int i = 0; i < num_columns; i++) {
        printf("%s ", columns[i].name);
    }
    printf("\n");

    // Parse and print rows
    while (fgets(row, MAX_ROW_LEN, file) != NULL) {
        char* col_val = strtok(row, ",");
        while (col_val != NULL && num_columns > 0) {
            printf("%s ", col_val);
            col_val = strtok(NULL, ",");
            num_columns--;
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}