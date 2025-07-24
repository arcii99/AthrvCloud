//FormAI DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>

/**
 * Compression Algorithm:
 * This algorithm uses run length encoding technique to compress the given input string.
 * It takes a string as input and returns the compressed string.
 * 
 * Example:
 * Input: AAABBBCCCDDE
 * Output: A3B3C3D2E1
 */

char* compress(char* str) {
    int len = strlen(str);
    char* compressed = (char*) malloc((len+1) * sizeof(char));
    int i = 0, j = 0;
    while(i < len) {
        int count = 0;
        char ch = str[i];
        while(i < len && str[i] == ch) {
            ++count;
            ++i;
        }
        compressed[j++] = ch;
        compressed[j++] = count + '0';
    }
    compressed[j] = '\0';
    return compressed;
}

int main() {
    char* input = "AAABBBCCCDDE";
    printf("Input: %s\n", input);
    char* output = compress(input);
    printf("Output: %s\n", output);
    return 0;
}