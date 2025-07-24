//FormAI DATASET v1.0 Category: Data recovery tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define FILE_NAME_LENGTH 8
#define FILE_EXTENSION_LENGTH 3

typedef unsigned char BYTE;

typedef struct __attribute__((__packed__))
{
    BYTE filename[FILE_NAME_LENGTH];
    BYTE extension[FILE_EXTENSION_LENGTH];
    BYTE attributes;
    BYTE reserved[10];
    unsigned short create_time;
    unsigned short create_date;
    unsigned short last_access_date;
    unsigned short last_modified_time;
    unsigned short last_modified_date;
    unsigned int size;
} DIR_ENTRY;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover [source file]\n");
        return 1;
    }

    // Open file for reading in binary mode
    FILE *infile = fopen(argv[1], "rb");
    if (infile == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int file_count = 0;
    FILE *outfile = NULL;

    while (fread(buffer, BLOCK_SIZE, 1, infile))
    {
        // Check if block starts with JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous output file if opened
            if (outfile != NULL)
            {
                fclose(outfile);
            }

            // Generate new file name
            char filename[12];
            sprintf(filename, "%03d.jpg", file_count);

            // Open new output file for writing in binary mode
            outfile = fopen(filename, "wb");
            if (outfile == NULL)
            {
                printf("Could not create file.\n");
                return 1;
            }

            // Increment file counter
            file_count++;
        }

        // Write buffer block to output file
        if (outfile != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }

    // Close input and output files
    fclose(infile);

    if (outfile != NULL)
    {
        fclose(outfile);
    }

    printf("Successfully recovered %d file(s).\n", file_count);

    return 0;
}