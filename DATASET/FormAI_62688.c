//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: shape shifting
#include <stdio.h>

int main() {
    printf("Welcome to the Checksum Calculator!\n");
    printf("Please enter the data to calculate checksum: ");

    char input[128];
    fgets(input, 128, stdin);

    int sum = 0;
    for (int i = 0; input[i] != '\n'; i++) {
        sum += (int) input[i];
    }

    printf("Checksum: %d\n", sum % 256);

    return 0;
}