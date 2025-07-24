//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

void textToBinary(char* input, char* output) {
    int len = strlen(input);
    for(int i=0;i<len;i++) {
        for(int j=7;j>=0;j--) {
            output[(i*8)+7-j] = ((input[i] >> j) & 0x1) + '0';
        }
    }
    output[len*8] = '\0';
}

void binaryToText(char* input, char* output) {
    int len = strlen(input) / 8;
    for(int i=0;i<len;i++) {
        output[i] = 0;
        for(int j=0;j<8;j++) {
            output[i] |= ((input[(i*8)+j] - '0') << (7-j));
        }
    }
    output[len] = '\0';
}

int main() {
    char text[MAX_LEN], binary[MAX_LEN*8], output[MAX_LEN];
    int key;
    printf("Enter the text to be watermarked:\n");
    fgets(text, MAX_LEN, stdin);
    printf("Enter the key for digital watermarking (must be an integer):\n");
    scanf("%d", &key);
    textToBinary(text, binary);
    int len = strlen(binary);
    for(int i=0;i<len;i++) {
        binary[i] += (key % 2) ? 1 : -1;
        key = (key << 1) | (key >> (sizeof(key)*8-1));
    }
    binaryToText(binary, output);
    printf("Watermarked text:\n%s", output);
    return 0;
}