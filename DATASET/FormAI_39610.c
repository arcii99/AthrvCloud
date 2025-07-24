//FormAI DATASET v1.0 Category: Data recovery tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2) {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open the memory card file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Memory allocation for buffer and filename
    unsigned char buffer[BLOCK_SIZE];
    char filename[8];

    // Initialize temporary variables
    int jpeg_count = 0;
    FILE *jpeg = NULL;

    // Go through the file block by block
    while (fread(&buffer, BLOCK_SIZE, 1, file)) {
        // Check if block starts with a JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            // Close previous JPEG file
            if (jpeg != NULL) {
                fclose(jpeg);
            }
            // Generate filename for new JPEG file
            sprintf(filename, "%.3i.jpg", jpeg_count);

            // Open new JPEG file for writing
            jpeg = fopen(filename, "w");
            if (jpeg == NULL) {
                fclose(file);
                printf("Could not create %s.\n", filename);
                return 1;
            }

            // Increment JPEG counter
            jpeg_count++;
        }

        // Write block data to open JPEG file
        if (jpeg != NULL) {
            fwrite(&buffer, BLOCK_SIZE, 1, jpeg);
        }
    }

    // Close any remaining open files
    if (jpeg != NULL) {
        fclose(jpeg);
    }
    fclose(file);

    return 0;
}