//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    // Open the CSV file
    FILE *fp;
    char *filename = "data.csv";
    fp = fopen(filename, "r");

    // Check if the file is opened successfully
    if (fp == NULL) {
        printf("Failed to open file %s.\n", filename);
        exit(1);
    }

    // Read in the CSV data
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        // Parse the line into tokens separated by comma
        char *token;
        token = strtok(line, ",");

        // Print out the tokens
        while (token != NULL) {
            printf("%s\t", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    // Close the file
    fclose(fp);

    // Free the allocated memory for getline()
    if (line) {
        free(line);
    }

    return 0;
}