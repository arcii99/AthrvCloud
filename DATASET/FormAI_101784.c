//FormAI DATASET v1.0 Category: Data recovery tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // open the input file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    // initialize variables
    unsigned char buffer[BLOCK_SIZE];
    int file_count = 0;
    char filename[8];
    FILE *output = NULL;

    // read the file block by block
    while (fread(buffer, sizeof(buffer), 1, input))
    {
        // check if block is the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // close previous output file (if any)
            if (output != NULL)
            {
                fclose(output);
            }

            // create new filename for the output file
            sprintf(filename, "%03i.jpg", file_count);

            // open new output file
            output = fopen(filename, "w");

            // increment file counter
            file_count++;
        }

        // write block to output file (if any)
        if (output != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, output);
        }
    }

    // close input file
    fclose(input);

    // close current output file (if any)
    if (output != NULL)
    {
        fclose(output);
    }

    // return success
    return 0;
}