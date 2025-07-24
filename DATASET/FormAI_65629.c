//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned char checksum = 0;

    // User input
    printf("Enter a string: ");
    char str[255];
    fgets(str, sizeof(str), stdin);

    // Calculation
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        checksum += str[i];
    }
    checksum = ~checksum + 1;  // Two's complement

    // Output
    printf("Checksum: 0x%02hhx\n", checksum);
    
    return 0;
}