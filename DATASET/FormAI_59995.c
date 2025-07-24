//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: puzzling
#include <stdio.h>

unsigned int hash(unsigned char *str) {
    unsigned int hash = 5381;

    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

int main(void) {
    printf("Welcome to the cryptic hashing program!\n");
    printf("Enter a string to be hashed: ");

    char input[256];
    fgets(input, 256, stdin);

    unsigned int hashed = hash(input);

    printf("\nHere is your hashed string: ");

    // This next part is where it gets puzzling!
    int i = 0;
    char output[9];
    sprintf(output, "%08x", hashed);

    while (output[i]) {
        output[i] ^= 0x55;
        output[i] = ~output[i];
        output[i] = (output[i] >> 4) | (output[i] << 4);
        output[i] ^= 0xAA;
        i++;
    }

    printf("%s\n", output);

    return 0;
}