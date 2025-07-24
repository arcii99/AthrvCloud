//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_LINE_LENGTH 1000
#define MAX_METADATA_LENGTH 1000

// function to extract metadata from a given line
void extract_metadata(char* line, char* metadata) {
    // initialize variables
    int i = 0, j = 0, start = 0, end = 0;
    // iterate through line
    while (line[i] != '\0') {
        // check for metadata start
        if (line[i] == '[') {
            start = i;
            // iterate through metadata
            while (line[i] != ']') {
                // check for end of line
                if (line[i] == '\0') {
                    printf("Error: no closing bracket found for metadata on line %s", line);
                    return;
                }
                // copy character to metadata
                metadata[j] = line[i];
                // update counters
                i++;
                j++;
            }
            // add null terminator to metadata
            metadata[j] = '\0';
            // set end index for metadata
            end = i;
            // print extracted metadata for testing
            printf("Metadata extracted: %s\n", metadata);
            // remove metadata from line
            memmove(&line[start], &line[end+1], strlen(line)-end);
            return;
        }
        // update counters
        i++;
    }
}

int main() {
    // initialize variables
    char line[MAX_LINE_LENGTH];
    char metadata[MAX_METADATA_LENGTH];
    // open file for reading
    FILE* file = fopen("example.txt", "r");
    // check if file was opened successfully
    if (file == NULL) {
        printf("Error: could not open file");
        return 1;
    }
    // iterate through lines in file
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // extract metadata from line
        extract_metadata(line, metadata);
        // print line without metadata for testing
        printf("Line without metadata: %s", line);
    }
    // close file
    fclose(file);
    return 0;
}