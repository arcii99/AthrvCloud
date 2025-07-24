//FormAI DATASET v1.0 Category: Compression algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define NO_OF_CHARS 256

char * compress(char * input_str) {
    int count[NO_OF_CHARS] = {0};
    int i, len = 0;
    char * compressed_str;
    for (i = 0; input_str[i]; i++) {
        count[input_str[i]]++;
    }

    for (i = 0; i < NO_OF_CHARS; i++) {
        if (count[i] > 0) {
            len++;
        }
    }
    
    compressed_str = (char *) calloc(len * 2 + 1, sizeof(char));
    for (i = 0, len = 0; i < NO_OF_CHARS; i++) {
        if (count[i] > 0) {
            compressed_str[len++] = i;
            compressed_str[len++] = count[i];
        }
    }
    compressed_str[len] = '\0';
    return compressed_str;
}

char * decompress(char * compressed_str) {
    int i, j, len = 0;
    char * decompressed_str;
    for (i = 1; compressed_str[i]; i += 2) {
        len += compressed_str[i];
    }
    decompressed_str = (char *) calloc(len + 1, sizeof(char));
    for (i = 0, j = 0; compressed_str[i]; i += 2) {
        int k;
        for (k = compressed_str[i+1]; k > 0; k--) {
            decompressed_str[j++] = compressed_str[i];
        }
    }
    decompressed_str[len] = '\0';
    return decompressed_str;
}

void test_compression(char * input_str) {
    char * compressed_str = compress(input_str);
    char * decompressed_str = decompress(compressed_str);

    printf("Input String: %s\n", input_str);
    printf("Compressed String: %s\n", compressed_str);
    printf("Decompressed String: %s\n", decompressed_str);

    free(compressed_str);
    free(decompressed_str);
}

int main(void) {
    char str_1[] = "aabbbccccddddeeeee";
    char str_2[] = "testing";
    char str_3[] = "hello";
    char str_4[] = "c compression";
    test_compression(str_1);
    test_compression(str_2);
    test_compression(str_3);
    test_compression(str_4);
    return 0;
}