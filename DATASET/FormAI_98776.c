//FormAI DATASET v1.0 Category: Data recovery tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Check for correct number of arguments
    if (argc != 2)
    {
        printf("Usage: %s image\n", argv[0]);
        return 1;
    }

    // Open input file
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Open output file
    char outfile_name[50];
    sprintf(outfile_name, "recovered_%s", argv[1]);
    FILE *outfile = fopen(outfile_name, "w");
    if (outfile == NULL)
    {
        printf("Could not create %s.\n", outfile_name);
        fclose(infile);
        return 1;
    }

    // Allocate memory for block buffer
    unsigned char *buffer = malloc(BLOCK_SIZE * sizeof(unsigned char));
    if (buffer == NULL)
    {
        printf("Memory allocation error.\n");
        fclose(infile);
        fclose(outfile);
        return 1;
    }

    // Initialize variables
    int jpg_count = 0;
    int bytes_read;
    FILE *current_jpg = NULL;

    // Loop through input file
    while ((bytes_read = fread(buffer, sizeof(unsigned char), BLOCK_SIZE, infile)) > 0)
    {
        // If the first four bytes match the jpeg signature, start a new file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous file if it's open
            if (current_jpg != NULL)
            {
                fclose(current_jpg);
            }

            // Generate filename and open new file for writing
            char filename[8];
            sprintf(filename, "%03i.jpg", jpg_count++);
            current_jpg = fopen(filename, "w");
            if (current_jpg == NULL)
            {
                printf("Could not create %s.\n", filename);
                fclose(infile);
                fclose(outfile);
                free(buffer);
                return 1;
            }
        }

        // Write buffer to output file if a jpeg file is open
        if (current_jpg != NULL)
        {
            fwrite(buffer, sizeof(unsigned char), bytes_read, current_jpg);
        }
    }

    // Close file pointers and free memory
    if (current_jpg != NULL)
    {
        fclose(current_jpg);
    }
    fclose(infile);
    fclose(outfile);
    free(buffer);

    return 0;
}