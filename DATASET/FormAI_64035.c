//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char *compress_string(char *str) {
    int i, j, count;
    char *compressed_str = (char*) malloc(sizeof(char) * MAX_SIZE);
    int len = strlen(str);

    // check if compressed string length is greater than original string
    if (len >= MAX_SIZE)
        return str;

    for (i = 0, j = 0; i < len; i++, j++) {
        compressed_str[j] = str[i];
        count = 1;
        while (str[i] == str[i+1]) {
            count++;
            i++;
        }
        if (count > 1) {
            char count_str[MAX_SIZE];
            sprintf(count_str, "%d", count);
            int k;
            for (k = 0; count_str[k] != '\0'; k++) {
                compressed_str[++j] = count_str[k];
            }
        }
    }
    compressed_str[++j] = '\0';

    return compressed_str;
}

int main() {
    char *str = "aaaabbbbbccccddddd";
    char *compressed_str = compress_string(str);

    printf("Original String: %s\n", str);
    printf("Compressed String: %s\n", compressed_str);

    free(compressed_str);
    return 0;
}