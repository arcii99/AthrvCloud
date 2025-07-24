//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: visionary
#include <stdio.h>

/**
 * This program computes a checksum for a given input file.
 * The program reads the contents of the file, sums the ASCII values of each character in the file,
 * and then computes the modulo (%) 255 value of the sum.
 */

/* Function to compute the checksum */
int checksum(char *filename) {
    
    FILE *fp;
    fp = fopen(filename, "r");      // Open file for reading
    
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return -1;
    }
    
    int c, sum = 0;
    while ((c = getc(fp)) != EOF) { // Read each character in file
        sum += c;                   // Add ASCII value of character to sum
    }
    
    fclose(fp);                     // Close file
    
    return sum % 255;               // Compute modulo 255 of sum
}

int main() {
    
    char *filename = "example.txt";
    int chksum = checksum(filename);
    
    if (chksum != -1) {
        printf("Checksum of file %s: %d\n", filename, chksum);
    }
    
    return 0;
}