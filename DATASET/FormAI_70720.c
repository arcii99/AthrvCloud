//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// function to extract metadata
void extract_metadata(const char* file_path) {
    FILE* fp = fopen(file_path, "r");
    
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    char line[MAX_SIZE];
    char* metadata[MAX_SIZE];
    int i = 0;
    
    // loop through each line of the file
    while (fgets(line, MAX_SIZE, fp)) {
        // check for metadata tag
        if (strstr(line, "metadata:")) {
            // tokenize line to extract metadata values
            char* token = strtok(line, ":");
            token = strtok(NULL, ",");
            while (token != NULL) {
                metadata[i++] = token;
                token = strtok(NULL, ",");
            }
            break;
        }
    }
    
    // print extracted metadata
    printf("Title: %s\n", metadata[0]);
    printf("Artist: %s\n", metadata[1]);
    printf("Album: %s\n", metadata[2]);
    
    fclose(fp);
}

int main() {
    char* file_path = "music.mp3";
    extract_metadata(file_path);
    return 0;
}