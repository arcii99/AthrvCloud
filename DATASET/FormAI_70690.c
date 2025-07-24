//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: recover [filename]");
        return 1;
    }

    // Open input file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Could not open file: %s", argv[1]);
        return 1;
    }

    // Initialize variables
    unsigned char buffer[BLOCK_SIZE];
    int block_count = 0;
    FILE *output_file = NULL;

    // Read input file block by block
    while (fread(buffer, BLOCK_SIZE, 1, input_file))
    {
        // Check for JPEG header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Found a JPEG header, so close current output file (if exists)
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            // Create a new output file
            char filename[8];
            sprintf(filename, "%03i.jpg", block_count);
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                printf("Could not create file: %s", filename);
                return 1;
            }

            // Increment block count
            block_count++;
        }

        // Write block to output file (if exists)
        if (output_file != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, output_file);
        }
    }

    // Close files
    fclose(input_file);
    if (output_file != NULL)
    {
        fclose(output_file);
    }

    return 0;
}