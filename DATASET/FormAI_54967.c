//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* file_name = "example.c";
    FILE* file_pointer;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    file_pointer = fopen(file_name, "r");
    if (file_pointer == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return 1;
    }

    while ((read = getline(&line, &len, file_pointer)) != -1) {
        char* token = strtok(line, " ");
        while (token != NULL) {
            if (strcmp(token, "int") == 0 || strcmp(token, "char") == 0 || strcmp(token, "double") == 0) {
                printf("Found data type %s\n", token);
            } else if (strcmp(token, "struct") == 0) {
                printf("Found struct\n");
            } else if (strcmp(token, "#include") == 0) {
                printf("Found include directive\n");
            } else if (strcmp(token, "//") == 0) {
                printf("Found comment\n");
            } else if (strcmp(token, "/*") == 0) {
                printf("Found start of comment\n");
            } else if (strcmp(token, "*/") == 0) {
                printf("Found end of comment\n");
            }
            token = strtok(NULL, " ");
        }
    }
    fclose(file_pointer);
    if (line) {
        free(line);
    }
    return 0;
}