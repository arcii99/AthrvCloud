//FormAI DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// function to compress input string
int compress(char* input, char* output) {
    int count = 1;
    char prev = input[0];
    int index = 0;
    
    for (int i = 1; i < strlen(input); i++) {
        if (input[i] != prev) {
            output[index++] = prev;
            output[index++] = count + '0';
            count = 1;
            prev = input[i];
        } else {
            count++;
        }
    }
    
    // add last character and count
    output[index++] = prev;
    output[index++] = count + '0';
    output[index] = '\0';
    
    return strlen(output);
}

// function to decompress input string
int decompress(char* input, char* output) {
    int index = 0;
    
    for (int i = 0; i < strlen(input); i += 2) {
        char ch = input[i];
        int count = input[i+1] - '0';
        
        for (int j = 0; j < count; j++) {
            output[index++] = ch;
        }
    }
    
    output[index] = '\0';
    
    return strlen(output);
}

int main() {
    char input[MAX_SIZE], output[MAX_SIZE];
    
    printf("Enter string to compress: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character
    
    int compressed_size = compress(input, output);
    printf("Compressed string: %s\n", output);
    printf("Compressed size: %d\n", compressed_size);
    
    char decompressed[MAX_SIZE];
    int decompressed_size = decompress(output, decompressed);
    printf("Decompressed string: %s\n", decompressed);
    printf("Decompressed size: %d\n", decompressed_size);
    
    if (strcmp(input, decompressed) == 0) {
        printf("Compression and decompression successful!\n");
    } else {
        printf("Compression and decompression unsuccessful :(\n");
    }
    
    return 0;
}