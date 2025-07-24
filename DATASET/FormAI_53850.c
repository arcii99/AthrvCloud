//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: happy
#include <stdio.h>
#include <string.h>

/* Function to extract metadata from a file */
void extractMetadata(char *filename) {
    char extension[4];

    /* Extracting file extension */
    memcpy(extension, &filename[strlen(filename)-3], 3);
    extension[3] = '\0';

    /* Checking the file extension */
    if (strcmp(extension, "txt") == 0) {
        printf("Metadata for .txt file: author: John Doe, date created: 7/15/2021, size: 759 bytes\n");
    }
    else if (strcmp(extension, "jpg") == 0) {
        printf("Metadata for .jpg file: resolution: 1920 x 1080, photographer: Jane Smith, date taken: 6/30/2021, size: 2.54 MB\n");
    }
    else if (strcmp(extension, "doc") == 0) {
        printf("Metadata for .doc file: author: Sam Johnson, date created: 5/17/2021, size: 5.31 MB\n");
    }
    else {
        printf("Sorry, metadata extraction not available for files with extension '%s'\n", extension);
    }
}

int main() {
    printf("Welcome to the C Metadata Extractor!\n\n");

    /* Prompt user for filename and extract metadata */
    char filename[50];
    printf("Enter the filename (with extension): ");
    scanf("%s", filename);

    extractMetadata(filename);

    return 0;
}