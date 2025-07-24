//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *fp;
    char filename[BUFFER_SIZE], buffer[BUFFER_SIZE];
    char *token;
    int row = 0, col = 0;

    printf("Enter the filename to read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, fp)) {
        col = 0;

        // Replace newline character with null character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Split the CSV row into tokens using comma as delimiter
        token = strtok(buffer, ",");

        while (token != NULL) {
            if (strlen(token) > 0) {
                printf("Row %d, Col %d: %s\n", row, col, token);
            }
            
            token = strtok(NULL, ",");
            col++;
        }

        row++;
    }

    printf("Total rows: %d\n", row);

    fclose(fp);

    return 0;
}