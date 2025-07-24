//FormAI DATASET v1.0 Category: Data recovery tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Check for correct command line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open input file
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        return 1;
    }

    // Initialize variables
    unsigned char buffer[BLOCK_SIZE];
    int file_count = 0;
    FILE *outfile = NULL;
    char filename[8];

    // Read from input file
    while (fread(buffer, BLOCK_SIZE, 1, infile))
    {
        // Check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If JPEG signature found, close any open file
            if (outfile != NULL)
            {
                fclose(outfile);
            }

            // Create new output filename
            sprintf(filename, "%03i.jpg", file_count);

            // Open output file
            outfile = fopen(filename, "w");
            if (outfile == NULL)
            {
                printf("Could not create %s\n", filename);
                return 1;
            }

            // Increment file count
            file_count++;
        }

        // If outfile is open, write to it
        if (outfile != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }

    // Close any open files
    fclose(infile);
    if (outfile != NULL)
    {
        fclose(outfile);
    }

    return 0;
}