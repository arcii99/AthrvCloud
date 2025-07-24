//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_LEN 1024

/* Function to extract metadata from a file */
int extract_metadata(char *filepath, char *metadata) {
    FILE *fp;
    char line[MAX_METADATA_LEN];
    int len = 0;
    
    fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filepath);
        return -1;
    }
    
    while (fgets(line, MAX_METADATA_LEN, fp) != NULL) {
        if (strncmp(line, "##", 2) == 0) {
            len += strlen(line);
            strcat(metadata, line);
        }
    }
    
    fclose(fp);
    
    if (len == 0) {
        printf("Error: no metadata found in file %s\n", filepath);
        return -1;
    }
    
    return 0;
}

/* Example usage */
int main() {
    char *filepath = "example_file.txt";
    char metadata[MAX_METADATA_LEN] = "";
    
    if (extract_metadata(filepath, metadata) == 0) {
        printf("Metadata:\n%s\n", metadata);
    }
    
    return 0;
}