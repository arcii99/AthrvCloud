//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
#define SIGNATURE_SIZE 4

void scan(char* file_path);

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 0;
    }

    char* file_path = argv[1];
    scan(file_path);

    return 0;
}

void scan(char* file_path) {
    FILE* fp;
    unsigned char buffer[BUF_SIZE];
    unsigned char signature[SIGNATURE_SIZE] = {0xE9, 0xF1, 0xDB, 0xEE}; // example signature

    fp = fopen(file_path, "rb");
    if(fp == NULL) {
        printf("ERROR: could not open file.\n");
        return;
    }

    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    int found = 0;
    for(long i = 0; i < size; i += BUF_SIZE - SIGNATURE_SIZE + 1) {
        size_t read_size = fread(buffer, 1, BUF_SIZE - SIGNATURE_SIZE + 1, fp);

        for(int j = 0; j < read_size - SIGNATURE_SIZE + 1; j++) {
            if(memcmp(buffer + j, signature, SIGNATURE_SIZE) == 0) {
                printf("WARNING: signature found at offset %ld\n", i + j);
                found = 1;
                break;
            }
        }

        if(found) {
            break;
        }
    }

    if(!found) {
        printf("No threats found.\n");
    }

    fclose(fp);
}