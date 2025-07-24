//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to extract metadata from a file
void extract_metadata(char *filename) {
    FILE *fp;
    char buffer[1024];
    char *line;

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    // loop through each line of the file
    while(fgets(buffer, sizeof(buffer), fp)) {
        // check if the line contains metadata information
        if(strstr(buffer, "METADATA:")) {
            line = strtok(buffer, ":");
            // extract metadata value from the line
            while(line != NULL) {
                if(strstr(line, "METADATA")) {
                    printf("Metadata: %s\n", strtok(NULL, "\n"));
                    break;
                }
                line = strtok(NULL, ":");
            }
        }
    }
    fclose(fp);
}

int main() {
    char filename[50];

    printf("Enter filename: ");
    scanf("%s", filename);

    extract_metadata(filename);

    return 0;
}