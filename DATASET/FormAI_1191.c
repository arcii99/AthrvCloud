//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to extract metadata from a file
void extractMetadata(char *filename) {

    // open the file in binary mode
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open file\n");
        return;
    }

    char *metadata = NULL;
    int length = 0;

    // loop through the file looking for the metadata
    while (!feof(fp)) {
        // read a chunk of data from the file
        char buffer[1024];
        int read = fread(buffer, 1, 1024, fp);
        if (read <= 0)
            break;

        // loop through the buffer looking for the metadata header
        for (int i = 0; i < read - 10; i++) {
            // check if the current byte is the start of the metadata header
            if (buffer[i] == 'M' && buffer[i+1] == 'E' && buffer[i+2] == 'T' && buffer[i+3] == 'A' &&
                buffer[i+4] == '-' && buffer[i+5] == 'I' && buffer[i+6] == 'N' && buffer[i+7] == 'F' &&
                buffer[i+8] == 'O' && buffer[i+9] == '-') {

                // calculate the length of the metadata
                length = (((int)buffer[i+10]) << 24) | (((int)buffer[i+11]) << 16) |
                        (((int)buffer[i+12]) << 8) | ((int)buffer[i+13]);

                // allocate memory for the metadata
                metadata = malloc(length + 1);
                if (metadata == NULL) {
                    printf("Error: Failed to allocate memory\n");
                    fclose(fp);
                    return;
                }

                // copy the metadata into the buffer
                memcpy(metadata, buffer + i + 14, length);
                metadata[length] = '\0';
            }
        }
    }

    // close the file
    fclose(fp);

    // display the metadata
    if (metadata != NULL) {
        printf("Metadata:\n%s\n", metadata);
        free(metadata);
    } else {
        printf("Error: Metadata not found\n");
    }
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: extract_metadata <filename>\n");
        return 1;
    }

    // extract the metadata from the file
    extractMetadata(argv[1]);

    return 0;
}