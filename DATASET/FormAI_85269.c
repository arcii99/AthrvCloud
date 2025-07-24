//FormAI DATASET v1.0 Category: Data recovery tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    // Check if enough arguments are provided
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open input file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Initialize variables
    BYTE buffer[BLOCK_SIZE];
    char filename[8];
    int filenumber = 0;
    FILE *outfile = NULL;

    // Read the input file in 512-byte blocks
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        // Check if block is the header of a JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If a JPEG file is already open, close it
            if (outfile != NULL)
            {
                fclose(outfile);
            }

            // Create a new filename and increment file counter
            sprintf(filename, "%03i.jpg", filenumber++);
            outfile = fopen(filename, "w");

            // Check if new file could be created
            if (outfile == NULL)
            {
                printf("Could not create %s.\n", filename);
                return 1;
            }
        }

        // Write block to current file
        if (outfile != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }

    // Close last file
    if (outfile != NULL)
    {
        fclose(outfile);
    }

    // Close input file
    fclose(file);

    return 0;
}