//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 20
#define MAX_ROWS 100

void parse_csv_file(char* filename){
    FILE *fp;
    char line[MAX_COLUMNS * 20], *token;
    char *headers[MAX_COLUMNS];
    char data[MAX_ROWS][MAX_COLUMNS][20];
    int row_index = 0;

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error opening file: %s", filename);
        exit(EXIT_FAILURE);
    }

    fgets(line, MAX_COLUMNS * 20, fp);
    token = strtok(line, ",");

    int column_index = 0;

    while(token != NULL && column_index < MAX_COLUMNS) {
        headers[column_index] = token;
        column_index++;
        token = strtok(NULL, ",");
    }

    while(fgets(line, MAX_COLUMNS * 20, fp) != NULL && row_index < MAX_ROWS) {
        column_index = 0;
        token = strtok(line, ",");

        while(token != NULL && column_index < MAX_COLUMNS) {
            strcpy(data[row_index][column_index], token);
            column_index++;
            token = strtok(NULL, ",");
        }

        row_index++;
    }

    fclose(fp);

    printf("CSV file %s has %d rows and %d columns\n", filename, row_index, column_index);
    printf("Headers:\n");

    for(int i = 0; i < column_index; i++) {
        printf("%s\t", headers[i]);
    }

    printf("\n");

    for(int i = 0; i < row_index; i++) {
        for(int j = 0; j < column_index; j++) {
            printf("%s\t", data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    parse_csv_file("example.csv");

    return 0;
}