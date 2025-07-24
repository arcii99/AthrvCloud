//FormAI DATASET v1.0 Category: Data recovery tool ; Style: creative
#include <stdio.h>
#include <stdlib.h>

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

    if (file == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];

    int jpg_count = 0;
    char filename[8];
    FILE *img = NULL;

    while (fread(buffer, BLOCK_SIZE, 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", jpg_count);
            img = fopen(filename, "w");
            jpg_count++;
        }

        if (img != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }

    fclose(file);

    return 0;
}