//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint32_t crypto_hash(const char *message) {

    /* Step 1 - Initializing Variables */
    
    uint32_t hash = 0x811c9dc5; // initial hash value
    uint32_t prime = 0x01000193; //  prime number
    uint32_t length = strlen(message); // length of the message
    uint32_t i = 0; // counter
    
    /* Step 2 - Hash Calculation */
    
    for (i = 0; i < length; i++) {
        hash = hash ^ message[i]; // XOR the current byte with hash
        
        hash = hash * prime; // multiply the hash by prime
    }

    /* Step 3 - Return the Hash Value */

    return hash;
}

int main() {

    /* Step 4 - Testing the Hash Function */

    char message[] = "Hello, world!"; // test message
    uint32_t result = crypto_hash(message); // get the hash value

    printf("Hash value of %s is %u\n", message, result); // print the result

    return 0;
}