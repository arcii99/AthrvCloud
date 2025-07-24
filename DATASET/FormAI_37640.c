//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

int main(void) {
    FILE* file = fopen("example.csv", "r");
    char line[MAX_LENGTH];

    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    printf("Reading from CSV file:\n");

    while (fgets(line, MAX_LENGTH, file) != NULL) {
        char* token = strtok(line, ",");
        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(file);

    return 0;
}