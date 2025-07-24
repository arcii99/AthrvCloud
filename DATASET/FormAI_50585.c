//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extract_metadata(char* filename);

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: ./metadata_extractor filename\n");
        return 1;
    }
    extract_metadata(argv[1]);
    return 0;
}

void extract_metadata(char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    char line[256];
    while(fgets(line, sizeof(line), fp)) {
        if(line[0] == '#') {
            printf("Metadata found: %s", line);
        }
        if(line[0] == '{') {
            int brace_count = 0;
            char metadata[256];
            strcpy(metadata, line);
            while(fgets(line, sizeof(line), fp)) {
                if(line[0] == '{') {
                    brace_count++;
                }
                if(line[0] == '}') {
                    brace_count--;
                    if(brace_count == 0) {
                        strcat(metadata, line);
                        printf("Metadata found: %s", metadata);
                        break;
                    }
                }
                strcat(metadata, line);
            }
        }
    }
    fclose(fp);
    return;
}