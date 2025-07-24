//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void extractMetadata(char* filename) {
    FILE* fp = fopen(filename, "rb");
    char buffer[MAX_SIZE];
    int count = 0;

    if (fp == NULL) {
        printf("Unable to open file %s", filename);
        return;
    }

    fseek(fp, -128, SEEK_END);
    fread(buffer, sizeof(char), 128, fp);

    if (memcmp(buffer, "TAG", 3) == 0) {
        printf("Metadata found for file %s\n", filename);
        count ++;
        printf("Title : %.*s\n", 30, buffer + 3);
        printf("Artist : %.*s\n", 30, buffer + 33);
        printf("Album : %.*s\n", 30, buffer + 63);
        printf("Year : %.*s\n", 4, buffer + 93);
    }
    else {
        printf("No metadata found for file %s\n", filename);
    }

    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage : %s filename.mp3\n", argv[0]);
        exit(1);
    }

    extractMetadata(argv[1]);

    return 0;
}