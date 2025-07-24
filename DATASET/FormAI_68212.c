//FormAI DATASET v1.0 Category: modern Encryption ; Style: recursive
#include <stdio.h>

// recursive encryption function
void encrypt(char* str, int key){
    // base case, end of string
    if(*str == '\0'){
        return;
    }
    else{
        // encrypt the current character
        *str = (*str + key) % 128;
        // call the function recursively with the next character and the same key
        encrypt(str + 1, key);
    }
}

int main(){
    char secretMsg[] = "This message is very secret!";
    int key = 5; // encryption key

    printf("Original message: %s\n", secretMsg);

    // encrypt the message recursively
    encrypt(secretMsg, key);

    printf("Encrypted message: %s\n", secretMsg);

    // decrypt the message by applying the opposite key recursively
    encrypt(secretMsg, 128 - key);

    printf("Decrypted message: %s\n", secretMsg);

    return 0;
}