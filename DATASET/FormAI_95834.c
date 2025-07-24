//FormAI DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This program demonstrates a unique compression algorithm that works by
 * replacing repetitive characters with a single byte that represents the
 * character and the number of times it appears. For example, if there are
 * eight consecutive 'A' characters, they are replaced by a single byte that
 * contains the value 'A' and the number 8.
 *
 * To compress a string, simply call the compress function with a pointer to 
 * the string and its length. The compressed string is returned as a new 
 * string and its length is also returned. To decompress a string, call the
 * decompress function with a pointer to the compressed string and its length.
 * The decompressed string is returned as a new string and its length is also
 * returned.
 */

 /**
  * This function compresses a string using a unique compression algorithm.
  *
  * @param str The string to be compressed
  * @param len The length of the string to be compressed
  * @return The compressed string and its length
  */
char* compress(char* str, int len) {
    char* compressed_str = (char*)malloc(len * sizeof(char));
    int index = 0;
    for (int i = 0; i < len; i++) {
        int count = 1;
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        if (count > 1) {
            compressed_str[index++] = str[i];
            compressed_str[index++] = count + '0';
        } else {
            compressed_str[index++] = str[i];
        }
    }
    compressed_str[index] = '\0';
    return strdup(compressed_str);
}

/**
 * This function decompresses a string that was compressed using the unique
 * compression algorithm.
 *
 * @param str The string to be decompressed
 * @param len The length of the string to be decompressed
 * @return The decompressed string and its length
 */
char* decompress(char* str, int len) {
    char* decompressed_str = (char*)malloc(len * sizeof(char));
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            int count = str[i] - '0';
            for (int j = 0; j < count - 1; j++) {
                decompressed_str[index++] = decompressed_str[index - 1];
            }
        } else {
            decompressed_str[index++] = str[i];
        }
    }
    decompressed_str[index] = '\0';
    return strdup(decompressed_str);
}

/**
 * This is the main function of the program.
 */
int main() {
    char str[] = "AAAAAAAAAABBCDEEEEEE";
    char* compressed_str = compress(str, strlen(str));
    printf("Compressed String: %s\n", compressed_str);

    char* decompressed_str = decompress(compressed_str, strlen(compressed_str));
    printf("Decompressed String: %s\n", decompressed_str);

    free(compressed_str);
    free(decompressed_str);
    return 0;
}