//FormAI DATASET v1.0 Category: Data recovery tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    unsigned char buffer[BLOCK_SIZE];
    int counter = 0;
    char filename[8];
    FILE *img = NULL;

    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        // check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // close previous file
            if (img != NULL)
            {
                fclose(img);
            }

            // create new file
            sprintf(filename, "%03i.jpg", counter++);
            img = fopen(filename, "w");

            if (img == NULL)
            {
                fclose(file);
                printf("Could not create file\n");
                return 1;
            }
        }

        // write block to file
        if (img != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    }

    fclose(file);
    fclose(img);
    return 0;
}