//FormAI DATASET v1.0 Category: Compression algorithms ; Style: futuristic
#include <stdio.h>
#include <string.h>

// Function to compress a given string using Run Length Encoding (RLE) algorithm
char* compress(char* str)
{
    int n = strlen(str);
    char* compressed = (char*) malloc(sizeof(char) * (n + 1));

    int i = 0, j = 0;
    while (i < n) {
        compressed[j++] = str[i];
        int count = 1;
        while (i + 1 < n && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        compressed[j++] = (char) (count + '0');
        i++;
    }

    compressed[j++] = '\0';
    return compressed;
}

// Function to decompress a given string using Run Length Encoding (RLE) algorithm
char* decompress(char* str)
{
    int n = strlen(str);
    char* decompressed = (char*) malloc(sizeof(char) * (n + 1));

    int i = 0, j = 0;
    while (i < n) {
        decompressed[j++] = str[i++];
        int count = str[i++] - '0';
        while (count--) {
            decompressed[j++] = str[i - 2];
        }
    }

    decompressed[j++] = '\0';
    return decompressed;
}

int main()
{
    char* str = "AAAAAAAAABBBBCCCCDDDDEEEE";
    char* compressed = compress(str);
    char* decompressed = decompress(compressed);

    printf("Original String: %s\n", str);
    printf("Compressed String: %s\n", compressed);
    printf("Decompressed String: %s\n", decompressed);

    free(compressed);
    free(decompressed);
    return 0;
}