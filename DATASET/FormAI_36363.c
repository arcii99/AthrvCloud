//FormAI DATASET v1.0 Category: Compression algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT_SIZE 100
#define MAX_COMPRESSED_SIZE 50

int main() {
    char input[MAX_INPUT_SIZE];
    char compressed[MAX_COMPRESSED_SIZE];
    int len, count, i, j, k;
    
    // Read input string from user
    printf("Enter a string to compress: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    len = strlen(input);
    
    // Compress the string
    i = 0;
    j = 0;
    while (i < len) {
        count = 1;
        while (i + count < len && input[i] == input[i + count]) {
            count++;
        }
        if (count > 1) {
            compressed[j++] = count + '0';
        }
        compressed[j++] = input[i];
        i += count;
    }
    compressed[j] = '\0';
    
    // Print the compressed string
    printf("Compressed string is: %s\n", compressed);
    
    // Decompress the string
    i = 0;
    j = 0;
    while (i < len && j < MAX_COMPRESSED_SIZE) {
        if (isdigit(compressed[i])) {
            count = compressed[i] - '0';
            for (k = 0; k < count; k++) {
                printf("%c", compressed[i+1]);
            }
            i += 2;
        } else {
            printf("%c", compressed[i]);
            i++;
        }
    }
    
    return 0;
}