//FormAI DATASET v1.0 Category: Data recovery tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define FILENAME_LEN 8

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    // check for proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // open the memory card file for reading
    FILE *f = fopen(argv[1], "r");

    // check if file exists
    if (f == NULL)
    {
        printf("Unable to open file: %s\n", argv[1]);
        return 1;
    }

    // allocate memory for buffer to hold a block of data
    BYTE buffer[BLOCK_SIZE];

    // keep track of the number of JPEG files found
    int jpg_count = 0;
    char filename[FILENAME_LEN];

    // pointer to the recovered file
    FILE *img = NULL;

    // read through the memory card block by block
    while (fread(&buffer, BLOCK_SIZE, 1, f) == 1)
    {
        // check if block matches the start of a JPEG file
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // if we already had a JPEG file open, close it
            if (img != NULL)
            {
                fclose(img);
            }

            // create a new filename for the JPEG file
            sprintf(filename, "%03i.jpg", jpg_count);

            // open the new JPEG file for writing
            img = fopen(filename, "w");

            // check if file exists
            if (img == NULL)
            {
                return 1;
            }

            // increment the JPEG count for the next file
            jpg_count++;
        }

        // if we have an open JPEG file, write the block to it
        if (img != NULL)
        {
            fwrite(&buffer, BLOCK_SIZE, 1, img);
        }
    }

    // close the last JPEG file
    fclose(img);

    // close the memory card file
    fclose(f);

    return 0;
}