//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100 // Maximum length of each cell in CSV

int main() {

    char filename[100];
    printf("Enter CSV file name (with extension): ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    char buffer[MAX_LEN];
    int row = 0, column = 0;

    while (fgets(buffer, MAX_LEN, fp)) {
        column = 0;
        row++;

        char* token = strtok(buffer, ",");

        while (token != NULL) {
            column++;
            printf("Row: %d, Column: %d, Value: %s\n", row, column, token);
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return 0;
}