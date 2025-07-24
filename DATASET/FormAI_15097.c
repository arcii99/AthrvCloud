//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Our unique cryptographic hash function */
uint32_t custom_hash(const char *str) {
    const uint32_t prime = 31;
    uint32_t hash = 0;

    /* Hash each character in the string using a simple formula */
    for (int i = 0; i < strlen(str); i++) {
        hash += (uint32_t) str[i] * prime;
        hash = hash << 3 | hash >> (32 - 3); /* Rotate hash left by 3 bits */
    }

    return hash;
}

int main() {
    /* Test our hash function */
    char message[] = "This is a test message!";
	
    /* Calculate the hash value */
    uint32_t hash_value = custom_hash(message);
	
    /* Print out the hash value */
    printf("Hash value: %u\n", hash_value);

    return 0;
}