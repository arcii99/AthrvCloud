//FormAI DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to compress the string
int compress(char *s, char *comp) {
    int len = strlen(s), count = 1, index = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == s[i+1]) {
            count++;
        } else {
            comp[index] = s[i];
            index++;
            if (count > 1) {
                char str[10];
                sprintf(str, "%d", count);
                for (int j = 0; str[j] != '\0'; j++) {
                    comp[index] = str[j];
                    index++;
                }
                count = 1;
            }
        }
    }
    comp[index] = '\0';
    return strlen(comp);
}

int main() {
    char original[100], compressed[100];
    printf("Enter a string to compress: ");
    scanf("%s", original);
    int len = compress(original, compressed);
    printf("Original string: %s\n", original);
    printf("Compressed string: %s\n", compressed);
    printf("Length of compressed string: %d\n", len);
    return 0;
}