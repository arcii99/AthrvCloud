//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define PARANOID_LENGTH 64 //length of the output hash

//rotate left operation for a 32-bit integer
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n)))) 

//paranoid prime for mixing up the input data
#define PARANOIA 0x9e3779b9

//main paranoid hash function
void paranoid_hash(const void *data, size_t size, void *hash_out) {
    const uint8_t *data_bytes = (const uint8_t *) data;
    size_t i;
    uint32_t final_hash[4] = {
        0xdeadbeef,
        0xcafebabe,
        0xbaadf00d,
        0x8badf00d
    }; //initial values of the 4 hash variables
    
    for (i = 0; i + 16 <= size; i += 16) { //process the input data in 16-byte chunks
        uint32_t chunk_hash[4];
        uint32_t chunk_words[4];
        
        chunk_words[0] = *((uint32_t *)(data_bytes + i));
        chunk_words[1] = *((uint32_t *)(data_bytes + i + 4));
        chunk_words[2] = *((uint32_t *)(data_bytes + i + 8));
        chunk_words[3] = *((uint32_t *)(data_bytes + i + 12));
        
        //mix up the input data with the paranoid prime
        chunk_words[0] += PARANOIA;
        chunk_words[1] += PARANOIA;
        chunk_words[2] += PARANOIA;
        chunk_words[3] += PARANOIA;
        
        //mix up the hash variables with the input data
        chunk_hash[0] = final_hash[0] ^ chunk_words[0];
        chunk_hash[1] = final_hash[1] ^ chunk_words[1];
        chunk_hash[2] = final_hash[2] ^ chunk_words[2];
        chunk_hash[3] = final_hash[3] ^ chunk_words[3];
        
        //mix up the hash variables with each other
        chunk_hash[0] ^= chunk_hash[1];
        chunk_hash[1] = ROTL(chunk_hash[1], 5) ^ chunk_hash[0] ^ chunk_hash[2];
        chunk_hash[2] = ROTL(chunk_hash[2], 8) ^ chunk_hash[1] ^ chunk_hash[3];
        chunk_hash[3] = ROTL(chunk_hash[3], 10) ^ chunk_hash[2] ^ chunk_hash[0];
        chunk_hash[0] = ROTL(chunk_hash[0], 13) ^ chunk_hash[3] ^ chunk_hash[1];
        chunk_hash[1] = ROTL(chunk_hash[1], 16) ^ chunk_hash[0] ^ chunk_hash[2];
        chunk_hash[2] = ROTL(chunk_hash[2], 19) ^ chunk_hash[1] ^ chunk_hash[3];
        chunk_hash[3] = ROTL(chunk_hash[3], 20) ^ chunk_hash[2] ^ chunk_hash[0];
        
        //mix up the hash variables with the paranoid prime again
        chunk_hash[0] += PARANOIA;
        chunk_hash[1] += PARANOIA;
        chunk_hash[2] += PARANOIA;
        chunk_hash[3] += PARANOIA;
        
        //store the resulting hash variables
        final_hash[0] = chunk_hash[0];
        final_hash[1] = chunk_hash[1];
        final_hash[2] = chunk_hash[2];
        final_hash[3] = chunk_hash[3];
    }
    
    //process the remaining input data that is less than 16 bytes
    uint32_t remaining_chunk[4] = { 0, 0, 0, 0 };
    for (size_t j = 0; i + j < size; j++) {
        remaining_chunk[j / 4] |= (uint32_t)data_bytes[i + j] << ((j % 4) * 8);
    }
    
    //mix up the input data with the paranoid prime
    remaining_chunk[0] += PARANOIA;
    remaining_chunk[1] += PARANOIA;
    remaining_chunk[2] += PARANOIA;
    remaining_chunk[3] += PARANOIA;
    
    //mix up the hash variables with the input data
    final_hash[0] ^= remaining_chunk[0];
    final_hash[1] ^= remaining_chunk[1];
    final_hash[2] ^= remaining_chunk[2];
    final_hash[3] ^= remaining_chunk[3];
    
    //mix up the hash variables with each other one more time
    final_hash[0] ^= final_hash[1];
    final_hash[1] = ROTL(final_hash[1], 5) ^ final_hash[0] ^ final_hash[2];
    final_hash[2] = ROTL(final_hash[2], 8) ^ final_hash[1] ^ final_hash[3];
    final_hash[3] = ROTL(final_hash[3], 10) ^ final_hash[2] ^ final_hash[0];
    final_hash[0] = ROTL(final_hash[0], 13) ^ final_hash[3] ^ final_hash[1];
    final_hash[1] = ROTL(final_hash[1], 16) ^ final_hash[0] ^ final_hash[2];
    final_hash[2] = ROTL(final_hash[2], 19) ^ final_hash[1] ^ final_hash[3];
    final_hash[3] = ROTL(final_hash[3], 20) ^ final_hash[2] ^ final_hash[0];
    
    //mix up the hash variables with the paranoid prime one last time
    final_hash[0] += PARANOIA;
    final_hash[1] += PARANOIA;
    final_hash[2] += PARANOIA;
    final_hash[3] += PARANOIA;
    
    //output the final hash as a byte array
    uint8_t *hash_bytes = (uint8_t *) hash_out;
    for (i = 0; i < PARANOID_LENGTH; i += 4) {
        hash_bytes[i] = (uint8_t) (final_hash[0] >> (i * 8));
        hash_bytes[i + 1] = (uint8_t) (final_hash[1] >> (i * 8));
        hash_bytes[i + 2] = (uint8_t) (final_hash[2] >> (i * 8));
        hash_bytes[i + 3] = (uint8_t) (final_hash[3] >> (i * 8));
    }
}

//helper function to print the hash result as a hexadecimal string
void print_hash(void *hash_out) {
    uint8_t *hash_bytes = (uint8_t *) hash_out;
    for (size_t i = 0; i < PARANOID_LENGTH; i++) {
        printf("%02x", hash_bytes[i]);
    }
    printf("\n");
}

int main() {
    //test the paranoid hash function with some example inputs
    char *msg1 = "Hello, world!";
    char *msg2 = "This is a test.";
    size_t msg1_len = strlen(msg1);
    size_t msg2_len = strlen(msg2);
    uint8_t hash1[PARANOID_LENGTH];
    uint8_t hash2[PARANOID_LENGTH];
    
    paranoid_hash(msg1, msg1_len, hash1);
    paranoid_hash(msg2, msg2_len, hash2);
    
    printf("The paranoid hash of \"%s\" is: ", msg1);
    print_hash(hash1);
    
    printf("The paranoid hash of \"%s\" is: ", msg2);
    print_hash(hash2);
    
    return 0;
}