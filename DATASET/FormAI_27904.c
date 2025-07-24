//FormAI DATASET v1.0 Category: Data recovery tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

typedef unsigned char byte;

bool is_jpeg_header(byte buffer[BLOCK_SIZE]) {
    return (buffer[0] == 0xff) &&
           (buffer[1] == 0xd8) &&
           (buffer[2] == 0xff) &&
           ((buffer[3] & 0xf0) == 0xe0);
}

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: recover image\n");
        return 1;
    }

    // Open input file
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL) {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    // Initialize variables
    byte buffer[BLOCK_SIZE];
    int n = 0;
    FILE *outfile = NULL;
    char filename[8];

    // Read blocks of the input file
    while (fread(buffer, sizeof(buffer), 1, infile)) {
        // If buffer contains JPEG header, close previous file and open new one
        if (is_jpeg_header(buffer)) {
            if (outfile != NULL) {
                fclose(outfile);
            }

            sprintf(filename, "%03i.jpg", n++);
            outfile = fopen(filename, "w");
            if (outfile == NULL) {
                fclose(infile);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 3;
            }
        }

        // If outfile is open, write buffer to it
        if (outfile != NULL) {
            fwrite(buffer, sizeof(buffer), 1, outfile);
        }
    }

    // Close outfile and infile
    if (outfile != NULL) {
        fclose(outfile);
    }
    fclose(infile);

    return 0;
}