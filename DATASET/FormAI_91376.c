//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Our unique cryptographic hash function
int myHash(char* str, int len){
    int hash = 0;
    for(int i = 0; i < len; i++){
        hash = (hash * 31 + (int) str[i]) % 1000000007;
    }
    return hash;
}

// Main function to test our unique cryptographic hash function
int main() {
    char input[100];
    printf("Enter a string to hash: ");
    scanf("%s", input);

    int length = strlen(input);
    int hash = myHash(input, length);
    printf("Hash value of string %s is %d\n", input, hash);

    return 0;
}