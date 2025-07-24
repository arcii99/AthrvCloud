//FormAI DATASET v1.0 Category: Compression algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to compress the input string
char* compress(char* input) {
    int len = strlen(input);
    char* output = (char*) malloc (sizeof(char) * (len + 1));
    int i = 0, j = 0;
    while (i < len) {
        int count = 1;
        output[j++] = input[i];
        while (i < len - 1 && input[i] == input[i+1]) {
            count++;
            i++;
        }
        if (count > 1) {
            char* count_str = (char*) malloc (sizeof(char) * 10);
            sprintf(count_str, "%d", count);
            int k = 0;
            while (count_str[k]) {
                output[j++] = count_str[k++];
            }
            free(count_str);
        }
        i++;
    }
    output[j] = '\0';
    return output;
}

// function to decompress a compressed string
char* decompress(char* input) {
    int len = strlen(input);
    char* output = (char*) malloc (sizeof(char) * (len + 1));
    int i = 0, j = 0;
    while (i < len) {
        if (input[i] >= '0' && input[i] <= '9') {
            int count = input[i] - '0';
            i++;
            while (input[i] >= '0' && input[i] <= '9') {
                count = count * 10 + (input[i] - '0');
                i++;
            }
            char current_char = output[j-1];
            for (int k = 0; k < count-1; k++) {
                output[j++] = current_char;
            }
        } else {
            output[j++] = input[i++];
        }
    }
    output[j] = '\0';
    return output;
}

int main() {
    char input[] = "Hello world! This is a sample input string.";
    char* compressed = compress(input);
    char* decompressed = decompress(compressed);
    printf("Input String: %s\n", input);
    printf("Compressed String: %s\n", compressed);
    printf("Decompressed String: %s\n", decompressed);
    free(compressed);
    free(decompressed);
    return 0;
}