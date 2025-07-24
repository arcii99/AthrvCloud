//FormAI DATASET v1.0 Category: Data recovery tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Check if user has provided a filename
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open file for reading
    FILE *file_ptr = fopen(argv[1], "r");
    if (file_ptr == NULL)
    {
        printf("Could not open image file.\n");
        return 1;
    }

    // Create buffer to read blocks of data
    unsigned char buffer[BLOCK_SIZE];

    // Keep track of current file number and file pointer
    int file_num = 0;
    FILE *current_file_ptr = NULL;

    // Read blocks of data until end of file
    while (fread(buffer, BLOCK_SIZE, 1, file_ptr) == 1)
    {
        // Check if current block is the start of a JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close current file if one is open
            if (current_file_ptr != NULL)
            {
                fclose(current_file_ptr);
            }

            // Create filename for new file
            char filename[8];
            sprintf(filename, "%03i.jpg", file_num);

            // Open new file for writing
            current_file_ptr = fopen(filename, "w");
            if (current_file_ptr == NULL)
            {
                fclose(file_ptr);
                printf("Could not create %s.\n", filename);
                return 1;
            }

            // Write block of data to new file
            fwrite(buffer, BLOCK_SIZE, 1, current_file_ptr);

            // Increment file number
            file_num++;
        }
        else
        {
            // If a JPEG file has been found, continue writing to the same file
            if (current_file_ptr != NULL)
            {
                fwrite(buffer, BLOCK_SIZE, 1, current_file_ptr);
            }
        }
    }

    // Close any open files
    if (current_file_ptr != NULL)
    {
        fclose(current_file_ptr);
    }
    fclose(file_ptr);

    return 0;
}