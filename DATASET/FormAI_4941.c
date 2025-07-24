//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declares array for key
int key[16];
// declares array for plaintext
int plaintext[16];
// declares array for encrypted data
int encrypted[16];
// declares array for decrypted data
int decrypted[16];

// random key generator function
void keygenerator(){
    srand(time(NULL));
    for(int i = 0; i < 16; i++){
        key[i] = rand() % 256;
    }
}

// encryption function
void encrypt(){
    for(int i = 0; i < 16; i++){
        encrypted[i] = plaintext[i] ^ key[i];
    }
}

// decryption function
void decrypt(){
    for(int i = 0; i < 16; i++){
        decrypted[i] = encrypted[i] ^ key[i];
    }
}

int main(){
    // initialize plaintext array
    plaintext[0] = 84;
    plaintext[1] = 104;
    plaintext[2] = 105;
    plaintext[3] = 115;
    plaintext[4] = 32;
    plaintext[5] = 105;
    plaintext[6] = 115;
    plaintext[7] = 32;
    plaintext[8] = 97;
    plaintext[9] = 32;
    plaintext[10] = 115;
    plaintext[11] = 101;
    plaintext[12] = 99;
    plaintext[13] = 114;
    plaintext[14] = 101;
    plaintext[15] = 116;

    // generate random key
    keygenerator();

    // encrypt plaintext
    encrypt();

    // decrypt encrypted data
    decrypt();

    // check if plaintext and decrypted data matches
    for(int i = 0; i < 16; i++){
        if(plaintext[i] != decrypted[i]){
            printf("Error: Plaintext and Decrypted data do not match!\n");
            exit(1);
        }
    }

    // print plaintext, key, encrypted data and decrypted data
    printf("Plaintext:\n");
    for(int i = 0; i < 16; i++){
        printf("%d ", plaintext[i]);
    }

    printf("\nKey:\n");
    for(int i = 0; i < 16; i++){
        printf("%d ", key[i]);
    }

    printf("\nEncrypted Data:\n");
    for(int i = 0; i < 16; i++){
        printf("%d ", encrypted[i]);
    }

    printf("\nDecrypted Data:\n");
    for(int i = 0; i < 16; i++){
        printf("%d ", decrypted[i]);
    }

    return 0;
}