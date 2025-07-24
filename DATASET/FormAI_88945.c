//FormAI DATASET v1.0 Category: Compression algorithms ; Style: curious
// Welcome to the Genius Compressor Algorithm!
// This algorithm uses a unique approach to compressing data
// It takes advantage of patterns that repeat themselves within the data

#include <stdio.h>
#include <stdlib.h>

// Define a function that takes a string and returns the compressed version of the string
char* compress(char* data) {
    int size = strlen(data);
    char* compressed = (char*) malloc(size * sizeof(char));
    int index = 0;

    for (int i = 0; i < size; i++) {
        int j = 0;

        // Count number of times the current character repeats itself
        while (data[i] == data[i+j] && (i+j) < size) {
            j++;
        }

        // If this is a repeating pattern, compress it
        if (j > 2) {
            compressed[index] = data[i];
            compressed[index+1] = j + '0'; // Store count as a single character
            index += 2;
            i += j - 1;
        } else {
            compressed[index] = data[i];
            index++;
        }
    }

    compressed[index] = '\0';
    return compressed;
}

int main() {
    char data[] = "aaaaaabbbcccddddeeeeeee";
    char* compressed = compress(data);

    printf("Original: %s\n", data);
    printf("Compressed: %s\n", compressed);

    free(compressed);
    return 0;
}