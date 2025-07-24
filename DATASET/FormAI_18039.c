//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

int main(int argc, char* argv[]) {
    FILE *fp;
    char line[MAX_LENGTH];
    char identifier[MAX_LENGTH];
    int line_num = 0;
    int is_multi_line_comment = 0;

    if(argc != 2) {
        printf("Usage: %s <source code filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    printf("Metadata in file %s:\n", argv[1]);

    // Read each line of the file
    while(fgets(line, MAX_LENGTH, fp)) {
        line_num++;

        // Check for comments
        char* comment_start = strstr(line, "/*");
        char* comment_end = strstr(line, "*/");
        if(comment_start != NULL && comment_end == NULL) {
            is_multi_line_comment = 1;
        }
        else if(comment_start == NULL && is_multi_line_comment == 1) {
            // Do nothing, continue until end of comment is found
        }
        else if(comment_start == NULL && comment_end != NULL) {
            is_multi_line_comment = 0;
        }
        else if(comment_start == NULL && comment_end == NULL && is_multi_line_comment == 1) {
            // Do nothing, still inside multi-line comment
        }
        else if(line[0] == '/' && line[1] == '/') {
            // Single-line comment found
            char* identifier_start = strstr(line, "//") + 2;
            strcpy(identifier, identifier_start);
            printf("\t- Line %d: Comment - %s", line_num, identifier);
        }
        else if(!is_multi_line_comment) {
            // Check for C identifiers
            char* identifier_start = line;
            do {
                identifier_start = strchr(identifier_start, '_');
                if(identifier_start != NULL) {
                    if(isalpha(identifier_start[1]) || identifier_start[1] == '_') {
                        // Found C identifier
                        strncpy(identifier, identifier_start, MAX_LENGTH);
                        identifier[MAX_LENGTH - 1] = '\0';
                        printf("\t- Line %d: C Identifier - %s\n", line_num, identifier);
                    }
                    identifier_start ++;
                }
            } while(identifier_start != NULL);
        }
    }

    fclose(fp);
    return 0;
}