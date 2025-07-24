//FormAI DATASET v1.0 Category: Data recovery tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    char *infile = argv[1];

    FILE *file = fopen(infile, "r");
    if (!file)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int file_counter = 0;
    char filename[8];

    FILE *jpg = NULL;

    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpg != NULL)
            {
                fclose(jpg);
            }

            sprintf(filename, "%03i.jpg", file_counter);
            jpg = fopen(filename, "w");
            file_counter++;
        }

        if (jpg != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, jpg);
        }
    }

    if (jpg != NULL)
    {
        fclose(jpg);
    }

    fclose(file);
    return 0;
}