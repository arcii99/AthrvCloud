//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mathematical
/* Unique C Compression Algorithm */

#include <stdio.h>
#include <math.h>

// Function that implements the compression algorithm
void compress(char str[]) {
    int len = strlen(str);
    int count = 1;

    for (int i = 1; i <= len; i++) {
        if (str[i] != str[i-1] || i == len) {
            printf("%c%d", str[i-1], count);
            count = 1;
        }
        else {
            count++;
        }
    }
}

int main() {
    char string[100];
    printf("Enter string to be compressed: ");
    scanf("%s", string);
    printf("Compressed string: ");
    compress(string);
    return 0;
}