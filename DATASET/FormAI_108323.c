//FormAI DATASET v1.0 Category: Data recovery tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

void recover(char *source)
{
    // Open the file to recover data from
    FILE *file = fopen(source, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file.\n");
        return;
    }

    // Create the output file
    char filename[8];
    int file_number = 0;
    FILE *image = NULL;

    unsigned char buffer[BLOCK_SIZE];
    int jpeg_found = 0;
    int bytes_read = 0;

    // Loop through blocks in the file
    while (fread(buffer, BLOCK_SIZE, 1, file) == 1)
    {
        // Check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the current file if we have one open
            if (jpeg_found == 1)
            {
                fclose(image);
            }
            else
            {
                jpeg_found = 1;
            }

            // Create the next file
            sprintf(filename, "%03i.jpg", file_number);
            image = fopen(filename, "w");
            if (image == NULL)
            {
                fclose(file);
                fprintf(stderr, "Could not create file.\n");
                return;
            }

            // Increment the file number
            file_number++;
        }

        // Write to the current file if we have one open
        if (jpeg_found == 1)
        {
            fwrite(buffer, BLOCK_SIZE, 1, image);
        }

        // Count bytes read
        bytes_read += BLOCK_SIZE;
    }

    // Check for errors
    if (ferror(file))
    {
        fclose(image);
        fclose(file);
        fprintf(stderr, "Error reading file.\n");
        return;
    }

    // Close the files
    fclose(image);
    fclose(file);

    // Print the number of bytes read
    printf("%i bytes read.\n", bytes_read);

    printf("Process complete.\n");
}

int main(int argc, char *argv[])
{
    // Check for correct number of arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Recover the data
    recover(argv[1]);

    return 0;
}