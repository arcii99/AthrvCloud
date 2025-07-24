//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from a file
void extract_metadata(char* file_name) {
    FILE* fp;
    char buffer[1024];
    char* tag_name;
    char* tag_value;
    int tag_count = 0;
    
    fp = fopen(file_name, "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    while(fgets(buffer, sizeof(buffer), fp)) {
        tag_name = strtok(buffer, ":");
        if(tag_name == NULL) continue;
        tag_value = strtok(NULL, "\n");
        if(tag_value == NULL) continue;
        printf("%s: %s\n", tag_name, tag_value);
        tag_count++;
    }
    
    if(tag_count == 0) {
        printf("No metadata found in file.\n");
    }
    
    fclose(fp);
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s file_name\n", argv[0]);
        return 1;
    }
    
    printf("Extracting metadata from file: %s\n", argv[1]);
    extract_metadata(argv[1]);
    
    return 0;
}