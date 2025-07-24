//FormAI DATASET v1.0 Category: Data recovery tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    // Ensure correct usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    char *infile = argv[1];

    // Open memory card file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // Initialize variables
    BYTE buffer[BLOCK_SIZE];
    int img_count = 0;
    FILE *outptr = NULL;
    char filename[8];

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr))
    {
        // Check if start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous JPEG file
            if (outptr != NULL)
            {
                fclose(outptr);
            }

            // Create new JPEG file
            sprintf(filename, "%03i.jpg", img_count++);
            outptr = fopen(filename, "w");
            if (outptr == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 3;
            }
        }

        // Write buffer to JPEG file
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outptr);
        }
    }

    // Close all open files
    fclose(outptr);
    fclose(inptr);

    return 0;
}