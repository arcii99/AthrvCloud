//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1024 // maximum length of input string
#define START_VAL 0xFF // initial checksum value

// function to calculate checksum
unsigned char checksum(char *str, size_t len) {
    unsigned char crc = START_VAL;
    int i;
    for(i = 0; i < len; i++) {
        crc ^= str[i];
        int j;
        for(j = 0; j < 8; j++) {
            if(crc & 0x80) {
                crc = (crc << 1) ^ 0x31;
            } else {
                crc <<= 1;
            }
        }
    }
    return crc;
}

int main() {
    char input[MAX_LEN];
    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin);

    // replace newline character with null character
    input[strcspn(input, "\n")] = '\0';

    // calculate checksum
    unsigned char result = checksum(input, strlen(input));
    printf("Checksum of '%s' = %#x\n", input, result);

    return 0;
}