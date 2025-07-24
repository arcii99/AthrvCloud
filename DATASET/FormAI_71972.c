//FormAI DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char* argv[])
{
    // check if user provides file path
    if (argc != 2) 
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // open file
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) 
    {
        printf("Error: Could not open file\n");
        return 1;
    }

    // variables to keep track of file information
    unsigned char buffer[BLOCK_SIZE];
    int jpg_count = 0;
    char filename[8];
    FILE* jpg = NULL;

    // iterate over blocks in file
    while (fread(buffer, BLOCK_SIZE, 1, file)) 
    {
        // check if block is start of a JPG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff 
            && (buffer[3] & 0xf0) == 0xe0) 
        {
            // close previous JPG file
            if (jpg != NULL) 
            {
                fclose(jpg);
            }
            // create new file
            sprintf(filename, "%03i.jpg", jpg_count);
            jpg = fopen(filename, "w");
            if (jpg == NULL) 
            {
                printf("Error: Could not create jpg file.\n");
                fclose(file);
                return 1;
            }
            // increment jpg counter
            jpg_count++;
        }
        // write block to current JPG file
        if (jpg != NULL) 
        {
            fwrite(buffer, BLOCK_SIZE, 1, jpg);
        }
    }

    // close file
    fclose(file);

    // close final JPG file
    if (jpg != NULL) 
    {
        fclose(jpg);
    }

    return 0;
}