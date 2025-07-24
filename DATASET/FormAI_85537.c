//FormAI DATASET v1.0 Category: Data recovery tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(1);
    }
    
    // open file for reading
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL) {
        printf("Could not open %s.\n", argv[1]);
        exit(2);
    }
    
    // create output file
    char filename[8];
    sprintf(filename, "%03i.jpg", 0);
    FILE *outptr = fopen(filename, "w");
    if (outptr == NULL) {
        fclose(inptr);
        printf("Could not create %s.\n", filename);
        exit(3);
    }
    
    // buffer to read BLOCK_SIZE bytes at a time
    unsigned char buffer[BLOCK_SIZE];
    
    int num_files = 0;
    int is_jpeg = 0;
    
    while (fread(buffer, BLOCK_SIZE, 1, inptr) == 1) {
        // check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            if (!is_jpeg) {
                is_jpeg = 1;
            } else {
                // close previous file
                fclose(outptr);
                
                // create new file
                num_files++;
                sprintf(filename, "%03i.jpg", num_files);
                outptr = fopen(filename, "w");
                if (outptr == NULL) {
                    fclose(inptr);
                    printf("Could not create %s.\n", filename);
                    exit(4);
                }
            }
        }
        
        if (is_jpeg) {
            // write buffer to file
            fwrite(buffer, BLOCK_SIZE, 1, outptr);
        }
    }
    
    // close final file
    fclose(outptr);
    
    // close input file
    fclose(inptr);
    
    return 0;
}