//FormAI DATASET v1.0 Category: Data recovery tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }

    // Open file and check for errors
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    // Declare variables
    int jpeg_count = 0;
    char filename[8];
    BYTE buffer[BLOCK_SIZE];
    FILE *img = NULL;

    // Read blocks of data
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        // Check for start of new JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous file
            if (jpeg_count > 0)
            {
                fclose(img);
            }

            // Create new file
            sprintf(filename, "%03i.jpg", jpeg_count);
            img = fopen(filename, "w");
            jpeg_count++;
        }

        // Write data to JPEG file if one is currently open
        if (jpeg_count > 0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    }

    // Close files
    if (img)
    {
        fclose(img);
    }
    fclose(file);

    return 0;
}