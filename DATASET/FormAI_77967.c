//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

unsigned int calculate_checksum(char *buffer, size_t buffer_size);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read = 0;
    unsigned int checksum = 0;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0)
    {
        checksum += calculate_checksum(buffer, bytes_read);
    }

    printf("Checksum: %u\n", checksum);

    fclose(file);

    return 0;
}

unsigned int calculate_checksum(char *buffer, size_t buffer_size)
{
    unsigned int checksum = 0;

    for (size_t i = 0; i < buffer_size; i++)
    {
        checksum += (unsigned int)buffer[i];
    }

    return checksum;
}