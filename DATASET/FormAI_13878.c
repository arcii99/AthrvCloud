//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16 // Number of Bytes in a block (128 bits)
#define KEYSIZE 32 // Key size in Bytes (256 bits)
#define ROUNDS 10 // Number of rounds

/*----------------- Helper Functions --------------------*/
typedef unsigned char byte; // byte type is alias for unsigned char type
typedef byte* block; // block type is a pointer type to byte type

/* Left Shifts the input block by the supplied number of bits */
void leftShift(block input, int numBits) {
    while (numBits--) { // For each bit to shift
        byte prevBit = (*input >> 7) & 1; // Get the MSB of current byte
        *input <<= 1; // Left Shift current byte by 1 bit
        *input |= prevBit; // Add the MSB from previous byte to LSB of current byte
        input++;
    }
}

/* Right Shifts the input block by the supplied number of bits */
void rightShift(block input, int numBits) {
    while (numBits--) { // For each bit to shift
        byte nextBit = (*(input+1) >> 7) & 1; // Get the MSB of next byte
        *input >>= 1; // Right Shift current byte by 1 bit
        *input |= nextBit << 7; // Add the MSB from next byte to LSB of current byte
        input++;
    }
}

/* XOR two input blocks and store the result in the destination block */
void blockXOR(block dest, block src1, block src2, int length) {
    while (length--) {
        *dest++ = *src1++ ^ *src2++;
    }
}

/* Takes a block of data and swaps its left and right halves */
void swapHalves(block input) {
    byte temp[BLOCK_SIZE/2];
    memcpy(temp, input, BLOCK_SIZE/2); // Copy Left Half to temporary array
    memcpy(input, input + BLOCK_SIZE/2, BLOCK_SIZE/2); // Copy Right Half to Left Half
    memcpy(input + BLOCK_SIZE/2, temp, BLOCK_SIZE/2); // Copy Left Half from temporary array to Right Half
}

/*----------------- Core Encryption Functions --------------------*/

/* Add Round Key Function */
void addRoundKey(block input, block key) {
    blockXOR(input, input, key, BLOCK_SIZE); // XOR the input block with the key
}

/* Substitution Box Function */
void substitutionBox(block input) {
    static const byte sBox[256] = { /* Substitution Box Values in Hexadecimal */
 0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
 0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
 0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
 0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
 0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
 0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
 0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
 0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
 0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
 0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
 0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
 0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
 0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
 0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
 0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
 0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16};

    for (int i = 0 ; i < BLOCK_SIZE ; i++) {
        input[i] = sBox[input[i]]; // Replace each byte with its corresponding substitution from sBox
    }
}

/* Permutation Function */
void permutation(block input) {
    /* define circular Shift left function */
    void circShiftLeft(block input, int numBits) {
        leftShift(input, numBits);
        rightShift(input, BLOCK_SIZE*8 - numBits); // Rotate the byte array right by 128 - numBits
    }

    /* define the P-Box and its order */
    static const int pBoxOrder[BLOCK_SIZE] = {6, 9, 11, 3, 15, 0, 4, 10, 13, 1, 7, 5, 14, 8, 2, 12};

    byte temp[BLOCK_SIZE];
    memcpy(temp, input, BLOCK_SIZE); // Copy the input block data to temporary array

    for (int i = 0 ; i < BLOCK_SIZE ; i++) {
        input[i] = temp[pBoxOrder[i]]; // Permute the input block data according to pBoxOrder
    }
    circShiftLeft(input, 19); // Left shift each byte by 19 bits
}


/* Main Encryption Function */
void encrypt(block input, block key) {
    /* Define Subkey Generation Functions */
    block subKeys[ROUNDS+1];
    void generateSubKeys(block key, block* subKeys) {
        /* Declare constants and variables */
        static const byte RCon[ROUNDS/2] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 }; // Constant used in subkey generation
        byte temp[BLOCK_SIZE];
        int i = 0;

        /* Set First Key */
        memcpy(subKeys[0], key, KEYSIZE);
        for (i = 1 ; i <= ROUNDS ; i++) {
            memcpy(temp, subKeys[i-1], BLOCK_SIZE); // Copy previous subkey to temporary array

            if (i % 2 == 0) { // If i is even
                byte tempByte = temp[0];
                leftShift(temp, 1); // Left Shift the bytes of the previous subkey
                temp[15] = tempByte; // Add the byte that was shifted out from index 0 to the end
                substitutionBox(temp); // S-Box Substitute the bytes of the previous subkey
                temp[0] ^= RCon[i/2-1]; // XOR the first byte of the previous subkey with a round constant
            }
            blockXOR(subKeys[i], subKeys[i-1], temp, BLOCK_SIZE); // XOR the previous subkey with the modified previous subkey to get the current subkey
        }
    }

    /* Generate Subkeys */
    generateSubKeys(key, subKeys);

    /* Add Initial Key */
    addRoundKey(input, subKeys[0]);

    /* Apply Rounds */
    for (int i = 1 ; i < ROUNDS ; i++) {
        substitutionBox(input);
        permutation(input);
        swapHalves(input);
        addRoundKey(input, subKeys[i]);
    }

    /* Apply Last Round (Without SwapHalves Function) */
    substitutionBox(input);
    permutation(input);
    addRoundKey(input, subKeys[ROUNDS]);
    swapHalves(input); // Swap halves at the end of the last round to finalize the block encryption
}

/*----------------- Main Program --------------------*/
int main() {
    /* Define Key and Input Blocks */
    block key = (block) malloc(KEYSIZE);
    block input = (block) malloc(BLOCK_SIZE);

    /* Populate Key and Input Blocks */
    memcpy(key, "ThisIsASecretKey1234", KEYSIZE);
    memcpy(input, "Hello World! This i", BLOCK_SIZE);

    /* Encrypt Input Block */
    encrypt(input, key);
    printf("Encrypted: ");

    /* Print Encrypted Block */
    for (int i = 0 ; i < BLOCK_SIZE ; i++) {
        printf("%02X ", input[i]);
    }
    printf("\n");

    return 0; // Terminate main program
}