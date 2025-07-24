//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_COL_LEN 100
#define MAX_DATA 1000

void readFile(char *filename);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Usage is csvReader <filename.csv>\n");
        exit(1);
    }

    readFile(argv[1]);

    return 0;
}

void readFile(char *filename) {
    FILE *fp;
    char buffer[MAX_DATA];
    char *fields[MAX_COLS];
    char *field;
    char output[MAX_COL_LEN * MAX_COLS];
    int colCount = 0;
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    while (fgets(buffer, MAX_DATA, fp) != NULL) {

        if (colCount == 0) {
            // On first line, determine number of columns
            field = strtok(buffer, ",");
            while (field) {
                fields[colCount++] = field;
                field = strtok(NULL, ",");
            }
            memset(output, '\0', sizeof(output));
            for (i = 0; i < colCount; i++) {
                strcat(output, fields[i]);
                strcat(output, "\t");
            }
            printf("%s\n", output);
        }
        else {
            // On subsequent lines, parse data into columns
            colCount = 0;
            field = strtok(buffer, ",");
            while (field) {
                fields[colCount++] = field;
                field = strtok(NULL, ",");
            }
            memset(output, '\0', sizeof(output));
            for (i = 0; i < colCount; i++) {
                strcat(output, fields[i]);
                strcat(output, "\t");
            }
            printf("%s\n", output);
        }
    }
    fclose(fp);
}