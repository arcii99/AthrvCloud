//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_METADATA_SIZE 1024

//Function to extract metadata from file 
char* extract_metadata(char* filepath) {
    FILE* file = fopen(filepath, "rb");
    if(file == NULL) {
        printf("Error Opening File\n");
        exit(1);
    }
    
    char* metadata = (char*) calloc(MAX_METADATA_SIZE, sizeof(char));
    if(metadata == NULL) {
        printf("Error Allocating Memory\n");
        exit(1);
    }
    
    int metadata_size = 0;
    char current_char;
    while(fread(&current_char, sizeof(char), 1, file) == 1) {
        if(current_char == '\n') { //metadata ends with newline character
            break;
        }
        metadata[metadata_size++] = current_char;
        if(metadata_size == MAX_METADATA_SIZE) {
            printf("Metadata Size Exceeded\n");
            exit(1);
        }
    }
    
    fclose(file);
    return metadata;
}

int main() {
    char* filepath = "example.mp3";
    char* metadata = extract_metadata(filepath);
    
    printf("Metadata Extracted from %s:\n%s\n", filepath, metadata);
    
    free(metadata);
    return 0;
}