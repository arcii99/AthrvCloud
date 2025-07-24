//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>

unsigned char calculateChecksum(const char* str, const int length) {
    unsigned char checksum = 0;
    
    for (int i = 0; i < length; i++) {
        checksum += str[i];
    }
    
    return checksum;
}

bool validateChecksum(const char* str, const int length, const unsigned char expected) {
    const unsigned char actual = calculateChecksum(str, length);
    return actual == expected;
}

int main() {
    char str[50];
    printf("Enter a string: ");
    fgets(str, 50, stdin);
    
    const int length = strlen(str);
    const unsigned char checksum = calculateChecksum(str, length);
    
    printf("Checksum: %02x\n", checksum);
    
    if (validateChecksum(str, length, checksum)) {
        printf("Checksum is valid.\n");
    } else {
        printf("Checksum is invalid.\n");
    }
    
    return 0;
}