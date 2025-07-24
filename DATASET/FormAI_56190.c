//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10

void print_csv(int rows, int cols, char csv[][MAX_COLS][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s", csv[i][j]);
            if(j != cols-1) printf(", ");
        }
        printf("\n");
    }
}

int main() {
    FILE* csv_file = fopen("example.csv", "r");

    if (csv_file == NULL) {
        printf("Could not open csv file\n");
        return 1;
    }

    int rows = 0, cols = 0;
    char csv[MAX_ROWS][MAX_COLS][100];
    char line[1000];

    while (fgets(line, 1000, csv_file) != NULL) {
        char* token = strtok(line, ",");
        cols = 0;
        while (token != NULL) {
            strcpy(csv[rows][cols], token);
            cols++;
            token = strtok(NULL, ",");
        }
        rows++;
    }

    fclose(csv_file);

    print_csv(rows, cols, csv);

    return 0;
}