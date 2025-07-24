//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define DELIMITER ","

int main() {
    char buffer[BUFFER_SIZE];
    char *field;

    FILE *file = fopen("data.csv", "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read header line
    if (fgets(buffer, BUFFER_SIZE, file)) {
        printf("Header: %s", buffer);
    }

    // Read data lines
    while (fgets(buffer, BUFFER_SIZE, file)) {
        field = strtok(buffer, DELIMITER);
        while (field) {
            printf("%s\t", field);
            field = strtok(NULL, DELIMITER);
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}