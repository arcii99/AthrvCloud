//FormAI DATASET v1.0 Category: Log analysis ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countLogFile(char *filename, int *lineCount, int *wordCount, int *charCount);

int main() {
    char filename[100];
    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;
    
    printf("Enter the filename to analyze: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0;  // remove newline character
    
    countLogFile(filename, &lineCount, &wordCount, &charCount);
    
    printf("The file %s has:\n", filename);
    printf("%d lines\n", lineCount);
    printf("%d words\n", wordCount);
    printf("%d characters\n", charCount);
    
    return 0;
}

void countLogFile(char *filename, int *lineCount, int *wordCount, int *charCount) {
    FILE *fptr;
    char buffer[100];
    int inWord = 0;
    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    
    while (fgets(buffer, 100, fptr) != NULL) {
        (*lineCount)++;
        (*charCount) += strlen(buffer);
        
        for (int i = 0; i < strlen(buffer); i++) {
            if (buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n') {
                inWord = 0;
            } else if (inWord == 0) {
                inWord = 1;
                (*wordCount)++;
            }
        }
    }
    
    fclose(fptr);
}