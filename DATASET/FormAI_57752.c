//FormAI DATASET v1.0 Category: Data recovery tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // check if user provided file to recover
    if (argc != 2)
    {
        printf("Usage: ./recover file-to-recover\n");
        return 1;
    }

    char *input_file_path = argv[1];

    // open input file
    FILE *input_file = fopen(input_file_path, "r");

    // check if input file exists and can be read
    if (input_file == NULL)
    {
        printf("File could not be opened.\n");
        return 1;
    }

    // initialize variables
    unsigned char buffer[BLOCK_SIZE];
    int file_count = 0;
    FILE *output_file = NULL;
    char output_file_name[8];

    // read input file block by block
    while (!feof(input_file))
    {
        // read block into buffer
        fread(buffer, sizeof(char), BLOCK_SIZE, input_file);

        // check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // close previous output file if it was opened
            if (output_file != NULL)
            {
                fclose(output_file);
                output_file = NULL;
            }

            // create new output file
            sprintf(output_file_name, "%03i.jpg", file_count);
            output_file = fopen(output_file_name, "w");
            file_count++;
        }

        // write buffer to output file if it was created
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), BLOCK_SIZE, output_file);
        }
    }

    // close input and output files
    fclose(input_file);
    if (output_file != NULL)
    {
        fclose(output_file);
    }

    return 0;
}