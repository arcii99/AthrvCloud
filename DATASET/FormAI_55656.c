//FormAI DATASET v1.0 Category: Data recovery tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define BLOCK_SIZE 512
#define FILE_NAME_LENGTH 8
#define FILE_EXTENSION_LENGTH 3
#define NEW_FILE "000.jpg"

typedef uint8_t BYTE;

bool is_jpeg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    // Checking that the user entered the correct command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open the card file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE]; // Buffer to read data
    bool found_first_jpeg = false; // Flag to know if the first jpeg was found
    int file_count = 0; // Count of how many files we have found
    char file_name[FILE_NAME_LENGTH + FILE_EXTENSION_LENGTH + 1]; // +1 for the null character at the end
    FILE *outfile = NULL; // Pointer to outfile
    sprintf(file_name, "%03i.jpg", file_count); // Create the first file name (000.jpg)
    outfile = fopen(file_name, "w");

    // Loop through the file, one block at a time
    while (fread(buffer, BLOCK_SIZE, 1, file) == 1)
    {
        // Check if the current block is a jpeg
        if (is_jpeg(buffer))
        {
            if (!found_first_jpeg) // If this is the first jpeg we find
            { 
                found_first_jpeg = true;
            }
            else // If this is not the first jpeg we find
            {
                fclose(outfile); // Close the previously opened outfile
                file_count++; // Increase the count of found files
                sprintf(file_name, "%03i.jpg", file_count); // Create the new file name
                outfile = fopen(file_name, "w"); // Open the new file
            }
        }

        if (found_first_jpeg) // If we have found the first jpeg
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile); // Write to the outfile
        }
    }

    fclose(file); // Close the original file
    fclose(outfile); // Close the last outfile

    return 0;
}

// Function to check if a block is a jpeg
bool is_jpeg(BYTE buffer[])
{
    return (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0);
}