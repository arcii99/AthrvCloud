//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_FIELDS 10
#define MAX_LENGTH 50

int main() {
    FILE *csv_file;
    char line[MAX_LENGTH];
    char* field;
    char* fields[MAX_FIELDS];
    char all_fields[MAX_LINES][MAX_FIELDS][MAX_LENGTH];
    int row = 0;
    int col = 0;
    
    csv_file = fopen("example.csv", "r");
    if (csv_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LENGTH, csv_file) != NULL && row < MAX_LINES) {
        field = strtok(line, ",");
        while (field != NULL && col < MAX_FIELDS) {
            fields[col] = field;
            strcpy(all_fields[row][col], field);
            col++;
            field = strtok(NULL, ",");
        }
        row++;
        col = 0;
    }

    printf("Rows: %d\n", row);
    printf("Columns: %d\n", col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%s ", all_fields[i][j]);
        }
        printf("\n");
    }

    fclose(csv_file);
    return 0;
}