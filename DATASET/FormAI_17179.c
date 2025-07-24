//FormAI DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char uncompressed[MAX_SIZE];
    char compressed[MAX_SIZE];
    int index, count, size;

    printf("Enter an uncompressed string: ");
    fgets(uncompressed, MAX_SIZE, stdin);
    uncompressed[strcspn(uncompressed, "\n")] = '\0'; // remove newline character

    size = strlen(uncompressed);
    index = count = 0;

    while (index < size) {
        compressed[count++] = uncompressed[index];
        int tempIndex = index;
        while (uncompressed[index] == uncompressed[tempIndex]) {
            tempIndex++;
        }

        if (tempIndex - index > 1) {
            char buffer[MAX_SIZE];
            sprintf(buffer, "%d", tempIndex - index);
            strcat(compressed, buffer);
            count += strlen(buffer);
        }
        index = tempIndex;
    }

    printf("Compressed string: %s\n", compressed);

    return 0;
}