//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string
char *compress(char *str)
{
    // Track the count of each character
    int count[256] = {0};
    int len = strlen(str);
    char *compressed_str = (char *)calloc(len+1, sizeof(char));
    int index = 0;

    // Count the number of occurrences of each character
    for(int i=0; i<len; i++) {
        count[str[i]]++;
    }

    // Copy each character and its count to the compressed string
    for(int i=0; i<len; i++) {
        if(count[str[i]] != -1) {
            compressed_str[index++] = str[i];
            compressed_str[index++] = count[str[i]] + '0';
            count[str[i]] = -1;
        }
    }
    return compressed_str;
}

int main(void)
{
    char *input_str = "mississippi";
    char *compressed_str = compress(input_str);

    printf("Original String: %s\n", input_str);
    printf("Compressed String: %s\n", compressed_str);

    free(compressed_str);
    return 0;
}