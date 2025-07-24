//FormAI DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }

    // Open input file
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        fprintf(stderr, "Could not open file.\n");
        return 2;
    }

    // Initialize variables
    BYTE buffer[BLOCK_SIZE];
    int jpg_count = 0;
    char filename[8];
    FILE *outfile = NULL;

    // Read through input file
    while (fread(buffer, BLOCK_SIZE, 1, infile))
    {
        // Check for start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous JPEG
            if (outfile != NULL)
            {
                fclose(outfile);
            }

            // Create new file name
            sprintf(filename, "%03i.jpg", jpg_count);

            // Open new output file
            outfile = fopen(filename, "w");
            if (outfile == NULL)
            {
                fclose(infile);
                fprintf(stderr, "Could not create file.\n");
                return 3;
            }

            // Update counter
            jpg_count++;
        }

        // Write to output file
        if (outfile != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }

    // Close any remaining files
    if (outfile != NULL)
    {
        fclose(outfile);
    }
    fclose(infile);

    // Exit program
    return 0;
}