//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

char* hashString(char *string){
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, string, strlen(string));
    SHA256_Final(hash, &sha256);
    char *output = (char*)malloc(65); // 64 hex characters plus null terminator
    int i;
    for(i=0; i<SHA256_DIGEST_LENGTH; i++){
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    output[64] = '\0'; // null terminate string
    return output;
}

int main(){
    char* string = "Romantic Programming"; // Your romantic string
    char* hashedString = hashString(string);
    printf("The hashed value is: %s\n", hashedString);
    free(hashedString);
    return 0;
}