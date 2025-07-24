//FormAI DATASET v1.0 Category: HTML beautifier ; Style: active
// This program is a unique C HTML beautifier example that takes an HTML file 
// and outputs a more readable version of the same file. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fileIn, *fileOut;
    char *inputFileName = "input.html";
    char *outputFileName = "output.html";
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fileIn = fopen(inputFileName, "r");
    if (fileIn == NULL) {
        printf("Unable to open input file.");
        return -1;
    }

    fileOut = fopen(outputFileName, "w");
    if (fileOut == NULL) {
        printf("Unable to create output file.");
        return -1;
    }

    while ((read = getline(&line, &len, fileIn)) != -1) {
        char *tokens = strtok(line, "<>");
        while(tokens != NULL) {
            fprintf(fileOut, "%s", tokens);
            tokens = strtok(NULL, "<>");
        }
        fprintf(fileOut, "\n");
    }

    fclose(fileIn);
    fclose(fileOut);

    return 0;
}