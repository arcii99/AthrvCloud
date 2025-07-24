//FormAI DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string
char* compress(char* str) {
    int n = strlen(str), count = 1, j = 0;
    char* compressed = (char*) malloc(sizeof(char) * (n + 1));

    for (int i = 0; i < n; i++) {
        if (str[i] != str[i+1] || i == n-1) {
            compressed[j++] = str[i];
            if (count > 1) {
                char* c = (char*) malloc(sizeof(char) * 10);
                sprintf(c, "%d", count); // convert count to string
                for (int k = 0; k < strlen(c); k++) {
                    compressed[j++] = c[k];
                }
                free(c);
                count = 1;
            }
        }
        else {
            count++;
        }
    }
    compressed[j] = '\0';
    return compressed;
}

int main() {
    char* str = "abbcccddddeeeeeffffff";
    char* compressed = compress(str);

    printf("Original string: %s\n", str);
    printf("Compressed string: %s\n", compressed);

    free(compressed);
    return 0;
}