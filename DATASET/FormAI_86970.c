//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARS_PER_LINE 1000
#define DELIMITER ','

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("Usage: %s filename.csv\n", argv[0]);
        exit(1);
    }

    int row = 0, col = 0;
    char buffer[MAX_CHARS_PER_LINE];
    char *data[MAX_LINES][MAX_CHARS_PER_LINE];

    FILE *fp = fopen(argv[1], "r");
    if(!fp) {
        printf("Unable to open file: %s\n", argv[1]);
        exit(1);
    }

    while(fgets(buffer, MAX_CHARS_PER_LINE, fp)) {
        col = 0;
        data[row][col] = strtok(buffer, ",");
        while(data[row][col] != NULL) {
            col++;
            data[row][col] = strtok(NULL, ",");
        }
        row++;
    }

    fclose(fp);

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }

    return 0;
}