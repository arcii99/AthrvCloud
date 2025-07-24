//FormAI DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100]; // maximum input size of 100 bytes
    printf("Enter a string to compress: ");
    scanf("%[^\n]", input); // read input until newline character is encountered
    
    int len = strlen(input); // get length of input string
    
    char compressed[len]; // create array to store compressed string
    int index = 0; // index for writing to compressed array
    
    // iterate over input string
    for(int i = 0; i < len; i++) {
        char curr = input[i]; // current character in input string
        int count = 1; // count of consecutive characters
        
        // iterate over consecutive characters
        for(int j = i + 1; j < len; j++) {
            if(input[j] == curr) {
                count++;
            } else {
                break;
            }
        }
        
        // write compressed string to array
        compressed[index++] = curr;
        char count_str[10]; // create string to represent count
        sprintf(count_str, "%d", count); // convert int to string
        strcat(compressed, count_str); // concatenate count to compressed string
        index += strlen(count_str); // update index based on length of count string
        
        i += count - 1; // skip over consecutive characters in input string
    }
    
    printf("Compressed string: %s\n", compressed);
    
    return 0;
}