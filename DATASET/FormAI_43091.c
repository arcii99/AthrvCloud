//FormAI DATASET v1.0 Category: Compression algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_BITS = 32;

void compress(char* inputString, char* outputString) {
    int len = strlen(inputString);
    int count = 0;
    char curr_char;
    int curr_char_count;

    for (int i = 0; i < len; i++) {
        if (i == 0) {
            curr_char = inputString[i];
            curr_char_count = 1;
        } else {
            if (inputString[i] == curr_char) {
                curr_char_count++;
            } else {
                outputString[count] = curr_char;
                count++;
                outputString[count] = curr_char_count + '0';
                count++;
                curr_char = inputString[i];
                curr_char_count = 1;
            }
        }
    }

    outputString[count] = curr_char;
    count++;
    outputString[count] = curr_char_count + '0';
    count++;
    outputString[count] = '\0';
}

void decompress(char* inputString, char* outputString) {
    int len = strlen(inputString);
    int count = 0;

    for (int i = 0; i < len; i += 2) {
        char curr_char = inputString[i];
        int curr_char_count = inputString[i + 1] - '0';

        for (int j = 0; j < curr_char_count; j++) {
            outputString[count] = curr_char;
            count++;
        }
    }

    outputString[count] = '\0';
}

int main() {
    char inputString[] = "hello world";
    char compressedString[MAX_BITS];
    char decompressedString[MAX_BITS];

    printf("Before compression: %s\n", inputString);
    compress(inputString, compressedString);
    printf("After compression: %s\n", compressedString);
    decompress(compressedString, decompressedString);
    printf("After decompression: %s\n", decompressedString);

    return 0;
}