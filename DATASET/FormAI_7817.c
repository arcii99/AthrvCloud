//FormAI DATASET v1.0 Category: Data recovery tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        exit(1);
    }

    char* infile = argv[1];
    FILE* inptr = fopen(infile, "r");

    if (inptr == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    char filename[8];
    unsigned char block[BLOCK_SIZE];

    int jpeg_count = 0;
    FILE* outptr = NULL;

    while (fread(block, BLOCK_SIZE, 1, inptr) == 1) {
        // Check if the block is a JPEG header
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0) {
            // Close the current JPEG file
            if (outptr != NULL) {
                fclose(outptr);
            }

            // Generate a new filename for the JPEG file
            sprintf(filename, "%03i.jpg", jpeg_count++);

            // Open the new JPEG file
            outptr = fopen(filename, "w");

            if (outptr == NULL) {
                printf("Cannot create file.\n");
                fclose(inptr);
                exit(1);
            }
        }

        // Write to the current JPEG file
        if (outptr != NULL) {
            fwrite(block, BLOCK_SIZE, 1, outptr);
        }
    }

    fclose(inptr);

    // Close the last JPEG file
    if (outptr != NULL) {
        fclose(outptr);
    }

    return 0;
}