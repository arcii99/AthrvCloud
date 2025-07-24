//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_LINE_LENGTH 1024

typedef struct Row {
    char cols[MAX_COLS][MAX_LINE_LENGTH];
    int num_cols;
} Row;

Row rows[MAX_ROWS];
int num_rows = 0;
int num_cols = 0;

void parse_csv_row(char *line) {
    int i = 0;
    char *token;

    while ((token = strtok(line, ",")) != NULL) {
        strcpy(rows[num_rows].cols[i], token);
        i++;
        line = NULL;
    }

    rows[num_rows].num_cols = i;
    num_rows++;
}

void read_csv(char *filename) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        parse_csv_row(line);
        if (num_cols == 0) {
            num_cols = rows[0].num_cols;
        }
    }

    fclose(fp);
}

void print_csv() {
    int i, j;

    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < rows[i].num_cols; j++) {
            printf("%s ", rows[i].cols[j]);
        }
        printf("\n");
    }
}

int main(int argc, char ** argv) {
    if (argc < 2) {
        printf("Usage: csv_reader <file.csv>\n");
        exit(EXIT_FAILURE);
    }

    read_csv(argv[1]);
    print_csv();
    
    return 0;
}