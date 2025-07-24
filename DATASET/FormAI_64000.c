//FormAI DATASET v1.0 Category: Compression algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// This shape-shifting compression algorithm compresses the data by changing the encoding method
// Based on the data pattern we have observed

int main() {
    char original[] = "ABBCCCDDDDDEEEEE";
    char compressed[100];
    int count = 0;
    char lastChar = original[0];
    int i = 0;
  
    // Iterate through the original data array
    while (original[i] != '\0') {

        // If the current character matches the last one, increase the count
        if (original[i] == lastChar) {
            count++;
        }
        // If the current character is different than the last one, save the last one and count
        // into the compressed array and reset count
        else {
            compressed[strlen(compressed)] = lastChar;
            compressed[strlen(compressed)] = count + '0';
            lastChar = original[i];
            count = 1;
        }

        i++;
    }

    // Add the last character to the compressed array
    compressed[strlen(compressed)] = lastChar;
    compressed[strlen(compressed)] = count + '0';
    compressed[strlen(compressed)] = '\0';

    printf("Original Data: %s\n", original);
    printf("Compressed Data: %s\n", compressed);

    // Decompress the data by reversing the process
    char decompressed[100];
    int j = 0;
    while (compressed[j] != '\0') {
        for (int k = 0; k < (compressed[j+1] - '0'); k++) {
            decompressed[strlen(decompressed)] = compressed[j];
        }
        j += 2;
    }
    decompressed[strlen(decompressed)] = '\0';

    printf("Decompressed Data: %s\n", decompressed);

    return 0;
}