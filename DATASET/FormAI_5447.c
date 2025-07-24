//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char filename[50];
    char line[100];
    int row = 0, col = 0;

    printf("Enter filename: "); 
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r"); 

    if (fp == NULL) { 
        printf("Could not open file %s", filename); 
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        row++;
        col = 0;
        char* token = strtok(line, ",");
        while (token != NULL) {
            col++;
            printf("Row %d, Col %d: %s", row, col, token);
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return 0;
}