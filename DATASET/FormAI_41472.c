//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 100
#define MAX_LINE_LEN 1024

int parse_csv_row(char *line, char **cols, int max_cols) {
    int num_cols = 0;
    char *pos = line;
    char *end;

    while (num_cols < max_cols - 1 && (end = strchr(pos, ',')) != NULL) {
        *end = '\0';
        cols[num_cols++] = pos;
        pos = end + 1;
    }

    cols[num_cols++] = pos;
    cols[num_cols] = NULL;

    return num_cols;
}

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    char line[MAX_LINE_LEN];
    char *cols[MAX_COLS];
    int num_cols;

    if (fp == NULL) {
        printf("Error: Couldn't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        num_cols = parse_csv_row(line, cols, MAX_COLS);

        for (int i = 0; i < num_cols; i++) {
            printf("%s ", cols[i]);
        }

        printf("\n");
    }

    fclose(fp);
    exit(EXIT_SUCCESS);
}