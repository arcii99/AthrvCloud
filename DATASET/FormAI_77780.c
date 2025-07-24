//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    char compressed[1000];
    int count = 1;
    char current;
    int i, j;

    printf("Enter string to compress: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    current = input[0];

    for (i = 1, j = 0; i <= strlen(input); i++) {
        if (input[i] == current) {
            count++;
        } else {
            compressed[j++] = count + '0';
            compressed[j++] = current;
            current = input[i];
            count = 1;
        }
    }

    compressed[j] = '\0';

    printf("Compressed string: %s\n", compressed);

    return 0;
}