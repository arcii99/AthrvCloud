//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
#include <stdio.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_LINE_LEN 100

typedef struct {
    char fields[MAX_COLS][MAX_LINE_LEN];
    int num_cols;
} Row;

Row csv[MAX_ROWS];
int num_rows = 0;

void parse_line(char* line) {
    int col_idx = 0;
    char* ptr = strtok(line, ",");
    while (ptr != NULL) {
        strcpy(csv[num_rows].fields[col_idx], ptr);
        col_idx++;
        ptr = strtok(NULL, ",");
    }
    csv[num_rows].num_cols = col_idx;
    num_rows++;
}

void print_csv() {
    int row_idx, col_idx;
    for (row_idx = 0; row_idx < num_rows; row_idx++) {
        for (col_idx = 0; col_idx < csv[row_idx].num_cols - 1; col_idx++) {
            printf("%s, ", csv[row_idx].fields[col_idx]);
        }
        printf("%s\n", csv[row_idx].fields[col_idx]);
    }
}

int main() {
    FILE* csv_file = fopen("data.csv", "r");
    if (csv_file == NULL) {
        printf("Failed to open data.csv\n");
        return -1;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), csv_file)) {
        parse_line(line);
    }

    fclose(csv_file);

    print_csv();

    return 0;
}