//FormAI DATASET v1.0 Category: HTML beautifier ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // check if file name is provided as argument
    if (argc < 2) {
        printf("Please provide file name as argument");
        return 0;
    }
    
    // open the file in read mode
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File \"%s\" not found", argv[1]);
        return 0;
    }
    
    // create a buffer to store file content
    char buffer[1000];
    int curIndex = 0;
    char lastChar; // to keep track of previous non-space character
    
    // read each line of file
    while (fgets(buffer, 1000, fp)) {
        int len = strlen(buffer);
        int i = 0;
        while (i < len) {
            if (buffer[i] != ' ') {
                lastChar = buffer[i];
                break;
            }
            i++;
        }
        
        // remove leading and trailing space from line
        char *line = strtok(buffer, " \t\n\r");
        printf("%s", line);
        
        // print space after previous non-space character
        if (lastChar != ';' && lastChar != '{' && lastChar != '}') {
            printf(" ");
        }
        curIndex += strlen(line) + 1;
    }
    fclose(fp);
    return 0;
}