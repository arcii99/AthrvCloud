//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(int argc, char **argv) {
    char filename[MAX_LENGTH];
    if (argc == 2) {
        strcpy(filename, argv[1]);
    } else {
        printf("Please provide a filename: ");
        fgets(filename, MAX_LENGTH, stdin);
        filename[strcspn(filename, "\n")] = '\0'; // Remove newline character from filename
    }

    FILE *fp;
    char line[MAX_LENGTH];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    // First line should contain column names
    fgets(line, MAX_LENGTH, fp);
    char *token = strtok(line, ",");
    while (token != NULL) {
        printf("%s\t", token);
        token = strtok(NULL, ",");
    }
    printf("\n");

    // Read remaining lines and print contents
    while (fgets(line, MAX_LENGTH, fp)) {
        token = strtok(line, ",");
        while (token != NULL) {
            printf("%s\t", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}