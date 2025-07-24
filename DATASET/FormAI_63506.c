//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 10
#define MAX_ROWS 100

struct data {
    char col1[20];
    char col2[20];
    int col3;
};

int main() {
    FILE *fp;
    char filename[] = "data.csv";
    char delim[] = ",";
    char line[100];
    char *token;
    int row_count = 0, col_count = 0;
    char *cols[MAX_COLS];
    struct data rows[MAX_ROWS];
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fgets(line, sizeof(line), fp); // Read header row
    token = strtok(line, delim);
    while (token != NULL && col_count < MAX_COLS) {
        cols[col_count++] = token;
        token = strtok(NULL, delim);
    }

    while (fgets(line, sizeof(line), fp) && row_count < MAX_ROWS) { // Read data rows
        token = strtok(line, delim);
        int i=0;
        while (token != NULL && i < col_count) {
            switch(i) {
                case 0:
                    strcpy(rows[row_count].col1, token);
                    break;
                case 1:
                    strcpy(rows[row_count].col2, token);
                    break;
                case 2:
                    rows[row_count].col3 = atoi(token);
                    break;
            }
            i++;
            token = strtok(NULL, delim);
        }
        row_count++;
    }

    fclose(fp);

    // Display data
    printf("%s\t%s\t%s\n", cols[0], cols[1], cols[2]);
    for (int i=0; i<row_count; i++) {
        printf("%s\t%s\t%d\n", rows[i].col1, rows[i].col2, rows[i].col3);
    }

    return 0;
}