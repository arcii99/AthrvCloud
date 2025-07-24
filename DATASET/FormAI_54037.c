//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

unsigned char checksum = 0;   // Define an 8-bit unsigned variable checksum and initialize it to zero

int main(int argc, char *argv[])
{
    // Verify that the user has entered the input file name as a command line argument
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    // Open the file in binary mode and verify that it was opened successfully
    FILE *infile = fopen(argv[1], "rb");
    if (infile == NULL) {
        printf("Cannot open %s\n", argv[1]);
        return 1;
    }
    
    int c = fgetc(infile);  // Read the first character from the input file
    
    while (c != EOF) {  // Continue reading characters until the end of file is reached
        checksum ^= c;  // XOR the checksum with the next character
        c = fgetc(infile);  // Read the next character from the input file
    }
    
    printf("Checksum of file '%s' is 0x%02X\n", argv[1], checksum);  // Output the final checksum in hexadecimal format
    
    fclose(infile);  // Close the input file
    
    return 0;
}