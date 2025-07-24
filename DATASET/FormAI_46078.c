//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("What do you mean we have to write a C Metadata Extractor program?! This makes no sense! I mean, who even uses metadata anyway?!\n");

    // Declaring an array of characters with file data
    char fileData[1000];
    int metadataCount = 0;
    // Initializing the data to some value to work with
    strcpy(fileData, "This file contains metadata: 5\n"
                     "metadata1: info1\n"
                     "metadata2: info2\n"
                     "metadata3: info3\n"
                     "metadata4: info4\n"
                     "metadata5: info5\n");
                     
    // Finding the metadata count
    char delimiter[] = ":";
    char *ptr = strtok(fileData, delimiter);  // Finding the first occurrence of delimiter
    while(ptr != NULL) {
        if(strncmp(ptr, "metadata", 8) == 0) {
            metadataCount++;
        }
        ptr = strtok(NULL, delimiter);  // Finding the next occurrence of delimiter
    }
    printf("Metadata Count: %d\n", metadataCount);  // Outputting the metadata count
    
    // Extracting metadata information
    char metadata[metadataCount][50];
    char *start = strstr(fileData, "metadata1: ");  // Finding the first occurrence of metadata
    for(int i=0; i<metadataCount; i++) {
        char *end = strstr(start, "\n");  // Finding the end of the metadata
        int length = end - start - strlen("metadata1: ");  // Calculating the length of the metadata
        strncpy(metadata[i], start + strlen("metadata1: "), length);  // Copying the metadata information to the array
        metadata[i][length] = '\0';  // Adding a null terminator to the end of the metadata string
        start = end + 1;  // Moving to the next metadata
    }
    
    // Outputting the metadata information
    printf("Metadata:\n");
    for(int i=0; i<metadataCount; i++) {
        printf("metadata%d: %s\n", i+1, metadata[i]);
    }

    return 0;
}