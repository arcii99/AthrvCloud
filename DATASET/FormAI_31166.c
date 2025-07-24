//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 100

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    char filename[MAX_CHARS];
    strcpy(filename, argv[1]);

    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error: file could not be opened\n");
        exit(1);
    }

    char buffer[MAX_CHARS];
    char metadata[MAX_CHARS];
    int metadata_length = 0;

    while(fgets(buffer, MAX_CHARS, file) != NULL) {
        if(buffer[0] == '[') {
            //start of metadata
            strcpy(metadata, buffer);
            metadata_length = strlen(buffer);
        }
        else if(buffer[0] == '\n') {
            //end of metadata
            break;
        }
        else {
            //append to metadata
            strcat(metadata, buffer);
            metadata_length += strlen(buffer);
        }
    }

    printf("Metadata: %s\n", metadata);

    fclose(file);
    return 0;
}