//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 100

// function to check if the given string is a valid C identifier
bool is_valid_identifier(char *str) {
    if (!isalpha(str[0]) && str[0] != '_') return false;
    for (int i = 1; i < strlen(str); i++) {
        if (!isalpha(str[i]) && !isdigit(str[i]) && str[i] != '_') return false;
    }
    return true;
}

// function to extract metadata from a C file
void extract_metadata(char *file_name) {
    char buffer[BUFFER_SIZE];
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: file not found.\n");
        return;
    }
    int line_num = 1;
    bool in_comment = false;
    bool in_function = false;
    char function_name[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        if (strstr(buffer, "/*")) {
            in_comment = true;
        }
        if (strstr(buffer, "*/")) {
            in_comment = false;
        }
        if (strstr(buffer, "int main(")) {
            printf("Main function found at line %d\n", line_num);
        }
        if (!in_comment && strstr(buffer, "void") && strstr(buffer, "(")) {
            in_function = true;
            sscanf(buffer, "%*s %s %*s", function_name);
            if (is_valid_identifier(function_name)) {
                printf("Function %s found at line %d\n", function_name, line_num);
            }
        }
        if (in_function && strstr(buffer, "{")) {
            printf("Function %s starts at line %d\n", function_name, line_num);
        }
        if (in_function && strstr(buffer, "}")) {
            in_function = false;
        }
        line_num++;
    }
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s file_name.c\n", argv[0]);
        return 1;
    }
    char *file_name = argv[1];
    extract_metadata(file_name);
    return 0;
}