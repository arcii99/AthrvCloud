//FormAI DATASET v1.0 Category: Compression algorithms ; Style: calm
// C program to compress a string using a unique compression algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress(char* str) {
    int len = strlen(str);

    // initialize empty string and count of repeated characters
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    int count = 0;

    for (int i = 0, j = 0; i < len; i++) {
        // increment count for every repeated character
        count++;

        // if next character is different, append the count and current character to the result
        if (i + 1 == len || str[i] != str[i + 1]) {
            res[j++] = count + '0';
            res[j++] = str[i];
            count = 0;
        }
    }

    // terminate the result string with null character
    res[len] = '\0';
    return res;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    char* compressed_str = compress(str);
    printf("Compressed string: %s\n", compressed_str);

    free(compressed_str); // free memory allocated to compressed string
    return 0;
}