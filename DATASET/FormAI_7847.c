//FormAI DATASET v1.0 Category: Syntax parsing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // Check if filename argument is provided
    if (argc != 2) {
        printf("Usage: ./syntax_parser <filename>\n");
        exit(1);
    }

    // Open file
    FILE *fp = fopen(argv[1], "r");
    
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file line by line
    char line[100];
    int line_number = 1;

    while (fgets(line, 100, fp)) {
        char *token = strtok(line, " "); // Get first token
        
        while (token != NULL) {
            // Check token for keywords and data types
            if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "char") == 0) {
                printf("Data type %s found on line %d.\n", token, line_number);
            }
            else if (strcmp(token, "if") == 0 || strcmp(token, "else") == 0 || strcmp(token, "while") == 0) {
                printf("Keyword %s found on line %d.\n", token, line_number);
            }
            
            // Check token for identifier or number
            else if (isdigit(token[0])) {
                printf("Number %s found on line %d.\n", token, line_number);
            }
            else if (isalpha(token[0])) {
                printf("Identifier %s found on line %d.\n", token, line_number);
            }

            token = strtok(NULL, " "); // Get next token
        }

        line_number++;
    }

    // Close file
    fclose(fp);

    return 0;
}