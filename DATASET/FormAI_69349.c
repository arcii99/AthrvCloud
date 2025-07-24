//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
// Welcome to the world of C Compression!
// This program features a unique compression algorithm that saves disk space with minimal loss of information.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Sample input string to compress
    char input[] = "abbcccddddeeeee";
    
    // Find length of input string and allocate memory for compressed string
    int len = strlen(input);
    char* compressed = (char*)malloc(sizeof(char) * (len*2));
    
    // Loop through input string and perform compression
    int i, j;
    for(i = 0, j = 0; i < len; i++) {
        int count = 1;
        
        // Count number of consecutive characters
        while(i < len-1 && input[i] == input[i+1]) {
            count++;
            i++;
        }
        
        // Add compressed string to output
        compressed[j++] = input[i];
        if(count > 1) {
            // Convert count to char array and add to compressed string
            char countStr[10];
            sprintf(countStr, "%d", count);
            for(int k = 0; k < strlen(countStr); k++) {
                compressed[j++] = countStr[k];
            }
        }
    }
    
    // Null terminate compressed string and print result
    compressed[j] = '\0';
    printf("Original String: %s\nCompressed String: %s\n", input, compressed);
    
    // Free memory and exit program
    free(compressed);
    return 0;
}