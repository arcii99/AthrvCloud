//FormAI DATASET v1.0 Category: File Backup System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    // Check for correct command-line arguments
    if (argc != 3)
    {
        printf("Usage: filebackup [source file] [destination file]\n");
        return 1;
    }

    // Open source file for reading
    FILE *source_file = fopen(argv[1], "rb");
    if (!source_file)
    {
        printf("Error: cannot open source file %s\n", argv[1]);
        return 1;
    }

    // Create destination file for writing
    FILE *destination_file = fopen(argv[2], "wb");
    if (!destination_file)
    {
        printf("Error: cannot create destination file %s\n", argv[2]);
        return 1;
    }

    // Create buffer for reading and writing
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // Read from source file and write to destination file
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, source_file)) > 0)
    {
        fwrite(buffer, sizeof(char), bytes_read, destination_file);
    }

    // Close files
    fclose(source_file);
    fclose(destination_file);

    printf("File backup complete!\n");

    return 0;
}