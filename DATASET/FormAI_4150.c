//FormAI DATASET v1.0 Category: Data recovery tool ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 512

void recover(FILE* file);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open the file with the given name
    char* filename = argv[1];
    FILE* file = fopen(filename, "r");

    if(file == NULL)
    {
        fprintf(stderr, "Could not open file %s\n", filename);
        return 2;
    }

    // Recover data
    recover(file);

    // Close the file
    fclose(file);

    return 0;
}

void recover(FILE* file)
{
    int file_counter = 0;
    char filename[BLOCK_SIZE];
    FILE* new_file = NULL;
    unsigned char block[BLOCK_SIZE];

    // Read blocks of data and search for JPEG headers
    while(fread(block, BLOCK_SIZE, 1, file) == 1)
    {
        // Check for the first four bytes of a JPEG file
        if(block[0] == 0xff && block[1] == 0xd8 &&
           block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            // If we already have an open file, close it
            if(new_file != NULL)
            {
                fclose(new_file);
            }

            // Create a new file name and open the file
            sprintf(filename, "%03i.jpg", file_counter++);
            new_file = fopen(filename, "w");

            if(new_file == NULL)
            {
                fprintf(stderr, "Could not create file %s\n", filename);
                return;
            }
        }

        // Write the block to the current file
        if(new_file != NULL)
        {
            fwrite(block, BLOCK_SIZE, 1, new_file);
        }
    }

    // Close the file if there is one still open
    if(new_file != NULL)
    {
        fclose(new_file);
    }
}