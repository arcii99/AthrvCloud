//FormAI DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to compress the given string
char* compress(char* str) {
    int len = strlen(str);
    if (len == 0) {
        return str;
    }
    bool flag = false;
    char* out = (char*)malloc(sizeof(char) * (len + 1));
    if (!out) {
        return NULL;
    }
    memset(out, 0, len + 1);
    int i = 0, j = 0;
    while (str[i] != '\0') {
        int count = 1;
        while (str[i] == str[i+1]) {
            count++;
            i++;
        }
        if (count > 1) {
            flag = true;
            out[j++] = str[i];
            out[j++] = count + '0';
        }
        else {
            out[j++] = str[i];
        }
        i++;
    }
    if (!flag) {
        free(out);
        return str;
    }
    return out;
}

int main(void) {
    printf("%s\n", compress("aaabccccddeee"));
    printf("%s\n", compress("abcdefg"));
    printf("%s\n", compress("aabbccddeeff"));
    printf("%s\n", compress(""));
    return 0;
}