//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define DELIMITER ","

int main() {
    FILE *fp;
    char filename[MAX_LEN];
    printf("Enter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char line[MAX_LEN];
    int row_num = 0;
    while (fgets(line, MAX_LEN, fp)) {
        if (row_num == 0) { // first row contains headers
            printf("Headers: %s", line);
        } else {
            char *token = strtok(line, DELIMITER);
            int column_num = 0;
            while (token != NULL) {
                if (column_num == 0) { // first column
                    printf("Row %d, Column %d (%s): ID = %s\n", row_num, column_num, DELIMITER, token);
                } else if (column_num == 1) { // second column
                    printf("Row %d, Column %d (%s): Name = %s\n", row_num, column_num, DELIMITER, token);
                } else if (column_num == 2) { // third column
                    printf("Row %d, Column %d (%s): Age = %s\n", row_num, column_num, DELIMITER, token);
                }
                token = strtok(NULL, DELIMITER);
                column_num++;
            }
        }
        row_num++;
    }
    fclose(fp);
    return 0;
}