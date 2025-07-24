//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// function to extract metadata from file
void extract_metadata(const char* filename) {
    FILE* fp;
    char buffer[255];

    fp = fopen(filename, "r"); // open file in read mode

    // check if file is opened successfully
    if (fp == NULL) {
        printf("Error: File '%s' not found\n", filename);
        exit(1); // terminate program
    }

    // loop through file to find metadata
    while (fgets(buffer, 255, fp)) {

        // check if line starts with #
        if (buffer[0] == '#') {
            printf("%s", buffer);
        }
        else { // metadata not found
            break;
        }
    }

    fclose(fp); // close file
}

int main() {
    char filename[255];

    // get filename from user
    printf("Enter filename: ");
    fgets(filename, 255, stdin);

    // remove newline character from filename
    filename[strcspn(filename, "\n")] = 0;

    // extract metadata from file
    extract_metadata(filename);

    return 0;
}