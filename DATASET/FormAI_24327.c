//FormAI DATASET v1.0 Category: Compression algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

// Function to compress a given string
void compress(char *src)
{
    int count = 1, n = strlen(src);
    char dest[SIZE];

    int i, j = 0;
    for (i = 0; i < n; i++) {
        if (src[i] == src[i + 1]) {
            count++;
        } else {
            dest[j++] = src[i];
            snprintf(&dest[j++], 3, "%d", count); // using snprintf to concatenate character and integer
            count = 1;
        }
    }
    dest[j] = '\0';

    printf("\nCompressed String: %s\n", dest);
}

int main()
{
    char src[SIZE];
    printf("Enter string: ");
    fgets(src, SIZE, stdin);
    src[strcspn(src, "\n")] = 0; // removing newline character

    printf("Original string: %s\n", src);

    compress(src);

    return 0;
}