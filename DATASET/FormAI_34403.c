//FormAI DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "server.log"
#define MAX_LINE_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <search term>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* search_term = argv[1];
    FILE* fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("Failed to open file '%s'\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }

    int line_count = 0;
    int hits_count = 0;
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        line_count++;
        if (strstr(line, search_term) != NULL) {
            hits_count++;
            printf("Match found on line %d: '%s'\n", line_count, line);
        }
    }

    if (hits_count == 0) {
        printf("No matches found for search term '%s'\n", search_term);
    } else {
        printf("Found %d matches for search term '%s'\n", hits_count, search_term);
    }

    fclose(fp);
    exit(EXIT_SUCCESS);
}