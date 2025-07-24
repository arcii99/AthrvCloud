//FormAI DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    // Open files
    FILE *source_fp = fopen(argv[1], "rb");
    if(!source_fp) {
        printf("Error: Unable to open %s\n", argv[1]);
        return 1;
    }

    FILE *destination_fp = fopen(argv[2], "wb");
    if(!destination_fp) {
        printf("Error: Unable to open %s\n", argv[2]);
        fclose(source_fp);
        return 1;
    }

    // Read from source and write to destination
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    int total_bytes_read = 0;
    while((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, source_fp)) > 0) {
        total_bytes_read += bytes_read;
        fwrite(buffer, sizeof(char), bytes_read, destination_fp);
    }

    // Close files
    fclose(source_fp);
    fclose(destination_fp);

    // Verify size of destination file matches source file
    FILE *verify_fp = fopen(argv[2], "rb");
    fseek(verify_fp, 0L, SEEK_END);
    int destination_size = ftell(verify_fp);
    fclose(verify_fp);

    if(destination_size == total_bytes_read) {
        printf("File recovery successful!\n");
        return 0;
    } else {
        printf("Error: Destination file size doesn't match source file size.\n");
        return 1;
    } 
}