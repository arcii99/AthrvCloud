//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to extract metadata from file
void extract_metadata(const char *filename) {
    FILE *fp;
    char line[MAX_LEN];
    char *key, *value;
    int line_num = 0;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("Metadata for file '%s':\n", filename);

    while (fgets(line, MAX_LEN, fp)) {
        line_num++;

        // Ignore comments and blank lines
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }

        // Split the line into key and value
        key = strtok(line, ":");
        value = strtok(NULL, "\n");

        // Print the key-value pair
        printf("%d. %s: %s\n", line_num, key, value);
    }

    fclose(fp);
}

int main() {
    char *filename = "example.txt";
    extract_metadata(filename);
    return 0;
}