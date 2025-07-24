//FormAI DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>

/**
 * @brief Compresses a string using the "FunnyZip" algorithm.
 * 
 * @param original The original string.
 * @param compressed Pointer to where the compressed string will be stored.
 * @return int The size of the compressed string.
 */
int funnyZip(char* original, char* compressed) {
    int count = 1;
    char current = original[0];
    int index = 0;
    int size = 0;

    while (current != '\0') {
        if (original[index + 1] == current) {
            count++;
        } else {
            compressed[size++] = current;
            if (count > 1) {
                char countStr[10];
                sprintf(countStr, "%d", count);
                for (int i = 0; countStr[i] != '\0'; i++) {
                    compressed[size++] = countStr[i];
                }
                count = 1;
            }
            current = original[index + 1];
        }
        index++;
    }

    compressed[size] = '\0';

    return size;
}

int main() {
    char original[] = "Hellooooo friend";
    char compressed[50];
    int compressedSize = funnyZip(original, compressed);

    printf("Original Size: %d\n", sizeof(original));
    printf("Compressed Size: %d\n", compressedSize);
    printf("Compressed String: %s\n", compressed);

    return 0;
}