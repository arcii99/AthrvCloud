//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_CHARS_PER_COL 100

int is_csv(char *filename) {
    char *ext = strchr(filename, '.');
    if (ext == NULL || strcmp(ext, ".csv") != 0) {
        return 0;
    }
    return 1;
}

int count_cols(char *line) {
    int count = 0;
    char *token = strtok(line, ",");
    while (token != NULL) {
        count++;
        token = strtok(NULL, ",");
    }
    return count;
}

int paranoid_csv_reader(char *filename) {
    if (!is_csv(filename)) {
        printf("Error: File is not a CSV\n");
        return 0;
    }
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        return 0;
    }
    char line[MAX_COLS * MAX_CHARS_PER_COL];
    char *token = NULL;
    int ncols = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (ncols == 0) {
            ncols = count_cols(line);
            if (ncols > MAX_COLS) {
                printf("Error: Too many columns\n");
                return 0;
            }
        } else {
            if (count_cols(line) != ncols) {
                printf("Error: Line has wrong number of columns\n");
                return 0;
            }
        }
        token = strtok(line, ",");
        while (token != NULL) {
            if (strlen(token) > MAX_CHARS_PER_COL) {
                printf("Error: Column has too many characters\n");
                return 0;
            }
            token = strtok(NULL, ",");
        }
    }
    return 1;
}

int main() {
    char filename[] = "example.csv";
    if (paranoid_csv_reader(filename)) {
        printf("SUCCESS: File is a valid CSV\n");
    }
    return 0;
}