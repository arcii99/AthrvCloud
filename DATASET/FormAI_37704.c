//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

int main() {
    char filename[MAX_SIZE], buffer[MAX_SIZE];
    char *value;

    printf("Enter the CSV file name: ");
    fgets(filename, MAX_SIZE, stdin);
    filename[strcspn(filename, "\n")] = 0;

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    // Read the first line of CSV
    if (fgets(buffer, MAX_SIZE, fp) == NULL) {
        printf("Error: file is empty\n");
        return -1;
    }

    // Split the first line into individual cells
    value = strtok(buffer, ",");
    while (value != NULL) {
        printf("%s\t", value);
        value = strtok(NULL, ",");
    }
    printf("\n");

    // Read and split the remaining lines
    while(fgets(buffer, MAX_SIZE, fp)) {
        value = strtok(buffer, ",");
        while(value != NULL) {
            printf("%s\t", value);
            value = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}