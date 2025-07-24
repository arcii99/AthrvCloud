//FormAI DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open input file
    FILE* img = fopen(argv[1], "r");
    if(img == NULL)
    {
        printf("Error: Could not open %s\n", argv[1]);
        return 1;
    }
    
    // Initialize variables
    unsigned char buffer[BLOCK_SIZE];
    int file_counter = 0;
    char filename[8];
    FILE* outfile = NULL;
    
    // Iterate through input file
    while(fread(buffer, BLOCK_SIZE, 1, img))
    {
        // Check if first 4 bytes of buffer match the JPEG signature
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If outfile is already open, close it
            if(outfile != NULL)
            {
                fclose(outfile);
            }
            
            // Create new filename and open outfile
            sprintf(filename, "%03i.jpg", file_counter);
            outfile = fopen(filename, "w");
            
            // Increment file_counter
            file_counter++;
        }
        
        // Write buffer data to current outfile
        if(outfile != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }
    
    // Close input and output files
    fclose(img);
    if(outfile != NULL)
    {
        fclose(outfile);
    }
    
    return 0;
}