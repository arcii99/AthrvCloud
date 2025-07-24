//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/sha.h>

//Function to create SHA256 hash
void createSHA256Hash(char* message, int messageLength, unsigned char* hash){
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, message, messageLength);
    SHA256_Final(hash, &sha256);
}

int main(){
    char message[] = "Hello, world!";
    int messageLength = strlen(message);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    
    //Create SHA256 hash and print it
    createSHA256Hash(message, messageLength, hash);
    printf("SHA256 hash of %s is : ", message);
    for(int i=0; i < SHA256_DIGEST_LENGTH; i++){
        printf("%02x", hash[i]);
    }
    printf("\n");
    
    return 0;
}