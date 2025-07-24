//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize variables
    int num = 1234;
    char str[50] = "This is a secret message";
    char key[50] = "mysecretkey";

    // Encryption algorithm
    int i;
    for(i = 0; i < strlen(str); i++) {
        str[i] = str[i] + key[i % strlen(key)];
    }
    num = num * 2;

    // Decryption algorithm
    for(i = 0; i < strlen(str); i++) {
        str[i] = str[i] - key[i % strlen(key)];
    }
    num = num / 2;

    // Output results
    printf("Encrypted message: %s\n", str);
    printf("Encrypted number: %d\n", num);
    printf("Decrypted message: %s\n", str);
    printf("Decrypted number: %d\n", num);
    
    return 0;
}