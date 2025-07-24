//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// post-apocalyptic C checksum calculator

int calculate_checksum(char* input) {
    int checksum = 0;
    int i = 0;

    // loop through input string, adding ASCII values to checksum
    while (input[i] != '\0') {
        checksum += (int) input[i];
        i++;
    }

    // apply random post-apocalyptic mutation to checksum
    checksum *= 17;
    checksum += 42;
    checksum %= 256;

    return checksum;
}

int main() {
    char input[1000];
    int checksum;

    printf("Enter string to calculate checksum: ");
    scanf("%s", input);

    checksum = calculate_checksum(input);

    printf("\nChecksum: %d\n", checksum);

    return 0;
}