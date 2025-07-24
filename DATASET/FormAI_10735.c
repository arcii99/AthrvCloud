//FormAI DATASET v1.0 Category: Data recovery tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

// Declare global variables
int jpegCount = 0;
char jpegName[8];

// Declare function prototypes
void writeToFile(unsigned char *buffer, int size, FILE *file);
int checkJpegHeader(unsigned char *buffer);
void newJpegFound(FILE **outfile, unsigned char *buffer, char *filename);

int main(int argc, char *argv[])
{
    // Check if user provided filename argument
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    char *filename = argv[1];

    // Open file and check for error
    FILE *infile = fopen(filename, "r");
    if (infile == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    // Declare buffer for reading infile blocks
    unsigned char buffer[BLOCK_SIZE];

    // Declare pointer variable for outfile and initialize to NULL
    FILE *outfile = NULL;

    // Loop through infile blocks
    while (fread(buffer, BLOCK_SIZE, 1, infile) == 1)
    {
        // Check if new jpeg signature found
        if (checkJpegHeader(buffer))
        {
            // If already writing to jpeg file, close it
            if (outfile != NULL)
            {
                fclose(outfile);
            }

            // Create new jpeg file
            newJpegFound(&outfile, buffer, filename);
        }

        // If already writing to jpeg file, write block to file
        if (outfile != NULL)
        {
            writeToFile(buffer, BLOCK_SIZE, outfile);
        }
    }

    // Close infile and outfile
    fclose(infile);
    if (outfile != NULL)
    {
        fclose(outfile);
    }

    // Print number of jpegs recovered
    printf("%i jpeg files recovered\n", jpegCount);

    return 0;
}

void writeToFile(unsigned char *buffer, int size, FILE *file)
{
    // Write buffer contents to file
    fwrite(buffer, size, 1, file);
}

int checkJpegHeader(unsigned char *buffer)
{
    // Check if buffer contains jpeg signature
    if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
        buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    return 0;
}

void newJpegFound(FILE **outfile, unsigned char *buffer, char *filename)
{
    // Increment jpeg count and format jpeg name
    jpegCount++;
    sprintf(jpegName, "%03i.jpg", jpegCount);

    // Create new jpeg file and check for error
    *outfile = fopen(jpegName, "w");
    if (*outfile == NULL)
    {
        printf("Could not create jpeg file\n");
        exit(1);
    }

    // Write first block to new jpeg file
    writeToFile(buffer, BLOCK_SIZE, *outfile);
}