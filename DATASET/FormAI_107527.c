//FormAI DATASET v1.0 Category: Syntax parsing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseC(char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    char c;
    int lineCount = 0, charCount = 0, wordCount = 0, commentCount = 0, bgCount = 0;

    while((c = fgetc(fp)) != EOF) {
        charCount++;

        if(c == '\n') {
            lineCount++;
        }

        if(c == ' ') {
            wordCount++;
        }

        // Look for comments
        if(c == '/' && (c = fgetc(fp)) == '/') {
            commentCount++;
            while((c = fgetc(fp)) != '\n');
            lineCount++;
            charCount = 0;
        } else if(c == '/' && (c = fgetc(fp)) == '*') {
            commentCount++;
            while((c = fgetc(fp)) != '*' || (c = fgetc(fp)) != '/') {
                if(c == '\n') {
                    lineCount++;
                }
            }
            charCount = 0;
        }

        // Look for brackets and parentheses
        if((c == '{' || c == '[' || c == '(') && bgCount == 0) {
            bgCount++;
        } else if((c == '}' || c == ']' || c == ')') && bgCount > 0) {
            bgCount--;
            if(bgCount == 0) {
                wordCount++;
            }
        }
    }

    printf("Line count: %d\n", lineCount);
    printf("Word count: %d\n", wordCount);
    printf("Comment count: %d\n", commentCount);
    fclose(fp);
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: ./parseC filename.c\n");
        return 1;
    }

    char* filename = argv[1];
    printf("Parsing %s\n", filename);
    parseC(filename);

    return 0;
}