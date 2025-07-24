//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 500 // maximum line length allowed for input files
#define MAX_TOKEN_LENGTH 100 // maximum length for a single word/token

void parse_resume(const char* filename) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char* token = strtok(line, " "); // tokenize line by space
        while (token != NULL) {
            if (strlen(token) <= MAX_TOKEN_LENGTH) {
                printf("%s ", token); // print token
            }
            token = strtok(NULL, " "); // get next token
        }
    }
    
    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    
    parse_resume(argv[1]);
    
    return 0;
}