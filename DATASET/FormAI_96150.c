//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }
    FILE *source_file = fopen(argv[1], "rb");
    if (!source_file) {
        perror(argv[1]);
        return 2;
    }
    FILE *destination_file = fopen(argv[2], "wb");
    if (!destination_file) {
        perror(argv[2]);
        return 3;
    }
    char buffer[BUF_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUF_SIZE, source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, destination_file);
    }
    fclose(source_file);
    fclose(destination_file);
    printf("Successfully synchronized file %s to %s\n", argv[1], argv[2]);
    return 0;  
}