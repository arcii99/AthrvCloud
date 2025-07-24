//FormAI DATASET v1.0 Category: Syntax parsing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_TOKEN_LENGTH 32

bool is_valid_c_program(char *filename);

int main(int argc, char *argv[]) {
    // Make sure the user supplied a filename
    if (argc < 2) {
        printf("Please provide a filename as an argument\n");
        return 1;
    }
    char *filename = argv[1];
    if (is_valid_c_program(filename)) {
        printf("%s is a valid C program\n", filename);
    } else {
        printf("%s is not a valid C program\n", filename);
    }
    return 0;
}

bool is_valid_c_program(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file: %s\n", filename);
        return false;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            if (strlen(token) > MAX_TOKEN_LENGTH) {
                printf("Error: token %s is too long\n", token);
                fclose(fp);
                return false;
            }
            // Check if the token is a valid C keyword
            const char *keywords[] = {
                "static", "int", "char", "if", "else", "while", "for"
            };
            bool is_keyword = false;
            int num_keywords = sizeof(keywords) / sizeof(char *);
            for (int i = 0; i < num_keywords; i++) {
                if (strcmp(token, keywords[i]) == 0) {
                    is_keyword = true;
                    break;
                }
            }
            if (!is_keyword && token[0] != '#') {
                printf("Error: invalid token found - %s\n", token);
                fclose(fp);
                return false;
            }
            token = strtok(NULL, " \t\n");
        }
    }
    fclose(fp);
    return true;
}