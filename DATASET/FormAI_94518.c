//FormAI DATASET v1.0 Category: Modern Encryption ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// This function is so secure not even an elephant can crack it!
int elephant_cryptography(char* str){
    int i;
    int length = strlen(str);
    for(i=0; i<length; i++){
        str[i] = str[i] ^ 51; // xor shifting with a prime number
    }
    return 0;
}

int main(){
    char message[100] = "I love elephants!";
    elephant_cryptography(message);
    printf("Encrypted message: %s\n", message);
    elephant_cryptography(message); // decrypting with the same function!
    printf("Decrypted message: %s\n", message);
    return 0;
}