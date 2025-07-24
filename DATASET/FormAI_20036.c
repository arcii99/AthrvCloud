//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// function to extract metadata information
void extract_metadata(char *filename)
{
    // open file
    FILE *fp;
    char buff[MAX_SIZE];
    fp = fopen(filename, "r");

    // check if file exists
    if (fp == NULL) {
        printf("Error: file does not exist or could not be opened.\n");
        exit(1);
    }

    // read file line by line
    int line_count = 1;
    while (fgets(buff, MAX_SIZE, fp)) {
        // check if line contains metadata
        int metadata_count = 0;
        char *line = strtok(buff, " ");
        while(line != NULL) {
            if (strncmp(line, "MD:", 3) == 0) {
                metadata_count++;
                printf("Metadata #%d found on line %d: %s\n", metadata_count, line_count, line);
            }
            line = strtok(NULL, " ");
        }

        line_count++;
    }

    // close file
    fclose(fp);
}

int main()
{
    char filename[MAX_SIZE];

    // get filename from user
    printf("Enter filename: ");
    fgets(filename, MAX_SIZE, stdin);
    filename[strcspn(filename, "\n")] = 0;

    // extract metadata information and print to console
    extract_metadata(filename);

    return 0;
}