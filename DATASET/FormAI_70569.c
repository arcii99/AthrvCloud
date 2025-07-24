//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Cyberpunk
#include <stdio.h>

#define MAX_SIZE 1000
#define COMPRESSED_SIZE 500

int main() {
    char original[MAX_SIZE];
    char compressed[COMPRESSED_SIZE];
    int i, j, count, length;

    printf("Enter a string to compress: ");
    fgets(original, MAX_SIZE, stdin);

    length = strlen(original);

    // compression algorithm
    for(i = 0, j = 0; i < length; i++) {
        count = 1;

        while(i < length - 1 && original[i] == original[i+1]) {
            count++;
            i++;
        }

        compressed[j++] = original[i];
        compressed[j++] = count + '0'; // store count as a char

        if(j >= COMPRESSED_SIZE) {
            printf("Error: Compressed string too long to store\n");
            printf("Maximum size is %d characters\n", COMPRESSED_SIZE);
            exit(1);
        }
    }

    printf("Original String: %s\n", original);
    printf("Compressed String: %s\n", compressed);

    return 0;
}