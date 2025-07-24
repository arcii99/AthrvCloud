//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[1024];
    int c, index = 0, sum = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[index] != '\0') {
        sum += str[index];
        index++;
    }

    printf("Checksum value: %d\n", sum % 256);

    return 0;
}