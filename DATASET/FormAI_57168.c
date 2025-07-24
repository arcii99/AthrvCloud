//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

typedef struct {
    int num_lines;
    int num_chars;
} metadata;

metadata extract_metadata(FILE *fp) {
    metadata data;
    data.num_lines = 0;
    data.num_chars = 0;
    
    char buffer[BUFSIZE];
    while (fgets(buffer, BUFSIZE, fp) != NULL) {
        data.num_lines++;
        int len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            len--;
        }
        data.num_chars += len;
    }
    
    return data;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }
    
    metadata data = extract_metadata(fp);
    printf("Number of lines: %d\n", data.num_lines);
    printf("Number of characters: %d\n", data.num_chars);
    
    fclose(fp);
    
    return 0;
}