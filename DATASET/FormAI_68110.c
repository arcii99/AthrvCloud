//FormAI DATASET v1.0 Category: Data recovery tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc != 2) {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL) {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    // Initialize variables
    unsigned char buffer[BLOCK_SIZE];
    int file_count = 0;
    FILE *img = NULL;
    char filename[8];

    // Read blocks from memory card until end of file
    while (fread(&buffer, BLOCK_SIZE, 1, card)) {
        // Check for start of JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            // Close previous file (if any)
            if (img != NULL) {
                fclose(img);
            }

            // Create new JPEG file
            sprintf(filename, "%03i.jpg", file_count);
            img = fopen(filename, "w");
            if (img == NULL) {
                fclose(card);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 3;
            }

            // Increment file count
            file_count++;
        }

        // Write block to JPEG file (if any)
        if (img != NULL) {
            fwrite(&buffer, BLOCK_SIZE, 1, img);
        }
    }

    // Close files and exit program
    fclose(img);
    fclose(card);
    return 0;
}