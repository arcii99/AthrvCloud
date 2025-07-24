//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[256];
    int sum = 0;
    int i;

    printf("Enter a message: ");
    fgets(input, 256, stdin);

    for (i = 0; input[i] != '\0'; i++) {
        sum += (int) input[i];
    }

    printf("Checksum = %d\n", sum);

    return 0;
}