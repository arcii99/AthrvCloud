//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/*** A simple cryptographic hash function using bitwise Xor and addition***/

/***Function to initialize the hash value***/
void init_hash(uint64_t* h) {
    *h = 0x5555555555555555;
}

/***Function to update the hash value with a given message***/
void update_hash(uint64_t* h, uint8_t* msg, size_t len) {
    for (size_t i = 0; i < len; i++) {
        *h ^= (uint64_t)msg[i];
        *h += (*h << 1) + (*h << 4) + (*h << 5) + (*h << 7) + (*h << 8) + (*h << 40);
    }
}

/***Function to finalize the hash value***/
void final_hash(uint64_t* h) {
    *h ^= (*h >> 33);
    *h *= 0xff51afd7ed558ccd;
    *h ^= (*h >> 33);
    *h *= 0xc4ceb9fe1a85ec53;
    *h ^= (*h >> 33);
}

/***Function to generate the hash value of a given message***/
void hash(uint8_t* msg, size_t len, uint64_t* hash_value) {
    init_hash(hash_value);
    update_hash(hash_value, msg, len);
    final_hash(hash_value);
}

/***Function to print the hash***/
void print_hash(uint64_t* h) {
    printf("0x%lx", *h);
}

int main()
{
    uint64_t hash_value;
    uint8_t message[] = "This is a test message!";
    size_t len = strlen((char*)message);

    hash(message, len, &hash_value);

    printf("The cryptographic hash value of '%s' is: ", message);
    print_hash(&hash_value);
    putchar('\n');

    return 0;
}