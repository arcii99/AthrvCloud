//FormAI DATASET v1.0 Category: Compression algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 512

/**
 * Compresses a given message using the run-length encoding algorithm.
 *
 * @param message The message to compress.
 * @param compressed The compressed output.
 * @return The length of the compressed message.
 */
int compress(const char *message, char *compressed) {
    char current_char = message[0];
    int count = 0, index = 0;
    int message_length = strlen(message);
    
    for (int i = 0; i < message_length; i++) {
        if (message[i] == current_char) {
            count++;
        } else {
            compressed[index++] = current_char;
            compressed[index++] = count;
            current_char = message[i];
            count = 1;
        }
    }
    
    // Add the final character and count to the compressed output
    compressed[index++] = current_char;
    compressed[index++] = count;
    
    return index;
}

/**
 * Decompresses a given message using the run-length decoding algorithm.
 *
 * @param compressed The compressed message to decompress.
 * @param decompressed The decompressed output.
 */
void decompress(const char *compressed, char *decompressed) {
    char current_char;
    int count, index = 0;
    int compressed_length = strlen(compressed);
    
    for (int i = 0; i < compressed_length; i += 2) {
        current_char = compressed[i];
        count = compressed[i+1];
        
        for (int j = 0; j < count; j++) {
            decompressed[index++] = current_char;
        }
    }
    
    // Add null terminator to end of decompressed output
    decompressed[index] = '\0';
}

int main() {
    char message[BUFFER_SIZE] = "aabbbccddddeeeeffffffggggggg";
    char compressed[BUFFER_SIZE], decompressed[BUFFER_SIZE];
    int compressed_length, decompressed_length;
    
    printf("Original message: %s\n", message);
    
    // Compress the message
    compressed_length = compress(message, compressed);
    
    printf("Compressed message: ");
    for (int i = 0; i < compressed_length; i++) {
        printf("%d ", compressed[i]);
    }
    printf("\n");
    
    // Decompress the message
    decompress(compressed, decompressed);
    
    printf("Decompressed message: %s\n", decompressed);
    
    return 0;
}