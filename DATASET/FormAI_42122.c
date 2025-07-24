//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Function to extract metadata from a file
void extract_metadata(char *filename, char *metadata) {
    // Open the file in read mode
    FILE *fp = fopen(filename, "r");
    
    // Check if file exists and can be opened
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }
    
    // Read the first line of the file
    char line[100];
    fgets(line, 100, fp);
    
    // Remove the newline character at the end of the line
    line[strcspn(line, "\n")] = 0;
    
    // Extract the metadata from the first line of the file
    sscanf(line, "Metadata: %s", metadata);
    
    // Close the file
    fclose(fp);
}

int main() {
    // List of filenames to extract metadata from
    char *filenames[] = {"file1.txt", "file2.txt", "file3.txt"};
    
    // Array to store the extracted metadata
    char metadata[3][100];
    
    // Extract metadata from each file using multiple threads
    #pragma omp parallel for
    for (int i = 0; i < 3; i++) {
        extract_metadata(filenames[i], metadata[i]);
    }
    
    // Print the extracted metadata for each file
    for (int i = 0; i < 3; i++) {
        printf("Metadata for file %s: %s\n", filenames[i], metadata[i]);
    }
    
    return 0;
}