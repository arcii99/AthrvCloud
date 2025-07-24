//FormAI DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compresses a string using a simple compression algorithm
// where each character is replaced with its frequency count.
// For example, "aaabbbcc" would be compressed to "a3b3c2".
char* compress(char *str) {
    int len = strlen(str);
    char *result = (char*)malloc((len * 2) + 1);
    int index = 0;
    for (int i = 0; i < len; i++) {
        char curr_char = str[i];
        int count = 1;
        while (i + 1 < len && str[i + 1] == curr_char) {
            count++;
            i++;
        }
        sprintf(&result[index], "%c%d", curr_char, count);
        index += 2;
    }
    result[index] = '\0';
    return result;
}

// Driver program to test the compression algorithm
int main() {
    char *str = "aaabbbcc";
    printf("Original string: %s\n", str);
    char *compressed_str = compress(str);
    printf("Compressed string: %s\n", compressed_str);
    free(compressed_str);
    return 0;
}