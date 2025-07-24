//FormAI DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 200

int compress(char *data, char *compressed_data) {
    int count = 0, index = 0;
    char ch = data[0];
    int len = strlen(data);

    for (int i = 0; i < len; i++) {
        if (data[i] == ch) {
            count++;
        } else {
            compressed_data[index++] = ch;
            compressed_data[index++] = '0' + count;
            count = 1;
            ch = data[i];
        }
    }

    // Add the last character and its count
    compressed_data[index++] = ch;
    compressed_data[index++] = '0' + count;
    compressed_data[index] = '\0';

    // Return total length of compressed data
    return strlen(compressed_data);
}

int main() {
    char data[MAX_LEN], compressed_data[MAX_LEN];
    printf("Enter a string: ");
    fgets(data, MAX_LEN, stdin);
    data[strcspn(data, "\n")] = '\0';
    int len = compress(data, compressed_data);
    printf("Original String: %s\n", data);
    printf("Compressed String: %s\n", compressed_data);
    printf("Length of Compressed String: %d\n", len);
    return 0;
}