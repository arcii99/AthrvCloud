//FormAI DATASET v1.0 Category: Compression algorithms ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** Compresses a given input string using a unique compression algorithm */
char *compress(char *input) {
    // Check if the input is null
    if (input == NULL) {
        printf("Error: input is null\n");
        return NULL;
    }
    
    int len = strlen(input);
    if (len == 0) {
        printf("Error: input is empty\n");
        return NULL;
    }
    
    // Create a buffer to store the compressed string
    char *buffer = malloc(sizeof(char) * (2 * len + 1));
    if (buffer == NULL) {
        printf("Error: failed to allocate buffer\n");
        return NULL;
    }
    
    // Initialize the buffer
    memset(buffer, 0, sizeof(char) * (2 * len + 1));
    
    int index = 0;
    char curr = input[0];
    int count = 1;
    int i;
    
    // Iterate through the input string
    for (i = 1; i < len; i++) {
        if (input[i] == curr) {
            count++;
        } else {
            // Append the count and the character to the buffer
            buffer[index++] = count + '0';
            buffer[index++] = curr;
            
            curr = input[i];
            count = 1;
        }
    }
    
    // Append the last group of characters to the buffer
    buffer[index++] = count + '0';
    buffer[index++] = curr;
    buffer[index] = '\0';
    
    // Free the input string and return the compressed string
    free(input);
    return buffer;
}

int main() {
    // Read input from the user
    printf("Enter a string to compress: ");
    char *input = NULL;
    size_t len = 0;
    getline(&input, &len, stdin);
    
    // Call the compression function
    char *compressed = compress(input);
    
    // Display the compressed string
    printf("Compressed string: %s\n", compressed);
    
    // Free the compressed string
    free(compressed);
    
    return 0;
}