//FormAI DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read and analyze logs
void analyzeLogs(char* filename, char* search_term) {
    FILE* fp;
    char* line = NULL;
    char* token = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;
    int num_lines = 0;

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read file line by line and count occurrences of search term
    while ((read = getline(&line, &len, fp)) != -1) {
        num_lines++;
        token = strtok(line, " ");
        while (token != NULL) {
            if (strcmp(token, search_term) == 0) {
                count++;
            }
            token = strtok(NULL, " ");
        }
    }

    // Print the results
    printf("Number of lines parsed: %d\n", num_lines);
    printf("Number of occurrences of \"%s\": %d\n", search_term, count);

    // Close the file
    fclose(fp);
}

int main() {
    char* filename = "system.log";
    char* search_term = "ERROR";

    // Analyze logs for occurrences of "ERROR"
    analyzeLogs(filename, search_term);

    return 0;
}