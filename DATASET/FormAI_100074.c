//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "r");

    if (!file) {
        printf("Unable to open file: %s\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char* tokens[MAX_LINE_LENGTH];
    int lines_read = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (strlen(line) == MAX_LINE_LENGTH - 1 && line[MAX_LINE_LENGTH - 2] != '\n') {
            printf("Line too long!\n");
            return 1;
        }
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        char* token = strtok(line, ",");
        int i = 0;
        while (token) {
            tokens[i++] = token;
            token = strtok(NULL, ",");
        }
        lines_read++;
    }

    fclose(file);

    printf("Read %d lines from file: %s\n", lines_read, filename);

    return 0;
}