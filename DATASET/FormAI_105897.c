//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to compress a string using the Cyberpunk algorithm */
void cyberpunk_compress(char* str) {
    int len = strlen(str);
    int count = 1;
    int i, j;

    for (i = 0, j = 1; j <= len; i++, j++) {
        if (str[i] == str[j]) {
            count++;
        } else {
            printf("%d%c", count, str[i]);
            count = 1;
        }
    }
    printf("\n");
}

int main() {
    char input[256];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = '\0';

    printf("Compressed string: ");
    cyberpunk_compress(input);

    return 0;
}