//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: complex
/* This program calculates the checksum of a given input file using the C programming language. 
 * The checksum is calculated as the bitwise XOR of all the bytes in the file.
 * The program takes the name of the input file as a command line argument and prints the checksum to stdout.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s input-file\n", argv[0]);
        exit(1);
    }
    
    FILE *in_file = fopen(argv[1], "rb"); // Open input file in binary mode
    if (in_file == NULL) {
        fprintf(stderr, "Error: could not open file '%s' for reading\n", argv[1]);
        exit(1);
    }
    
    unsigned char byte = fgetc(in_file); // Read first byte
    unsigned char checksum = byte; // Initialize checksum
    
    while (byte != EOF) {
        byte = fgetc(in_file); // Read next byte
        if (byte != EOF) {
            checksum ^= byte; // XOR with checksum
        }
    }
    
    printf("Checksum of file '%s': 0x%02x\n", argv[1], checksum);
    
    fclose(in_file); // Close input file
    
    return 0; // Exit program
}