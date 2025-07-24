//FormAI DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program uses a unique compression algorithm to compress input strings
// The algorithm works as follows:
// First, it replaces all consecutive sequences of the same character with a single instance of that character and a count.
// Then, it replaces all occurrences of the substring "the" with the character '@'.
// Finally, it replaces all occurrences of the substring "ing" with the character '#'.

char* compress(char* str) {
    int len = strlen(str);
    char* compressed = (char*) malloc(len * 2 + 1);
    int i = 0;
    int j = 0;
    while (i < len) {
        int count = 1;
        compressed[j] = str[i];
        while (i + 1 < len && str[i] == str[i+1]) {
            count++;
            i++;
        }
        if (count > 1) {
            compressed[j+1] = count + '0';
            j += 2;
        } else {
            j++;
        }
        i++;
    }
    compressed[j] = '\0';
    char* tmp = (char*) malloc(j + 1);
    strcpy(tmp, compressed);
    free(compressed);
    compressed = tmp;
    char from[] = "the";
    char to = '@';
    char* p = compressed;
    while ((p = strstr(p, from))) {
        *p = to;
    }
    char from2[] = "ing";
    char to2 = '#';
    p = compressed;
    while ((p = strstr(p, from2))) {
        *p = to2;
    }
    return compressed;
}

int main() {
    char* input = "Hellooooo thereeeeee, how are youuuu doinggggg?";
    printf("Input string: %s\n", input);
    char* compressed = compress(input);
    printf("Compressed string: %s\n", compressed);
    free(compressed);
    return 0;
}