//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *filename = NULL;
    FILE *fp = NULL;
    char buffer[BUFFER_SIZE];
    char *token = NULL;
    char *csv_row[10]; // Maximum columns supported in a single row

    if (argc < 2) {
        printf("Error: Please specify a CSV filename\n");
        return 1;
    }

    filename = argv[1];
    fp = fopen(filename, "r");

    if (!fp) {
        printf("Error: Failed to open file %s\n", filename);
        return 1;
    }

    // Read CSV row by row
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        int row_num = 0;
        token = strtok(buffer, ",");
        
        // Split CSV row into individual cells and store in csv_row array
        while (token != NULL) {
            csv_row[row_num] = token;
            row_num++;
            token = strtok(NULL, ",");
        }

        // Print each cell value in the current row
        for (int i = 0; i < row_num; i++) {
            printf("%s ", csv_row[i]);
        }

        printf("\n");
    }

    fclose(fp);

    return 0;
}