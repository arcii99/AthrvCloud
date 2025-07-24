//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: all-encompassing
/* A simple implementation of the RSA public key encryption algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// calculate the greatest common divisor
int gcd(int a, int b){
    int r;
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// calculate the private key
int private_key(int p, int q, int e){
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int k = 1;
    while((k * phi + 1) % e){
        k++;
    }
    return (k * phi + 1) / e;
}

// encrypt a message using the public key
int encrypt(unsigned char* message, int message_len, int e, int n, unsigned char* encrypted_message){
    int i;
    int num_blocks = (int)ceil(message_len / 2.0);
    int* blocks = (int*)malloc(num_blocks * sizeof(int));
    for(i = 0; i < message_len; i += 2){
        blocks[i / 2] = (message[i] << 8) | message[i + 1];
    }
    for(i = 0; i < num_blocks; i++){
        blocks[i] = (int)pow(blocks[i], e) % n;
        encrypted_message[i * 2] = (blocks[i] >> 8) & 0xFF;
        encrypted_message[i * 2 + 1] = blocks[i] & 0xFF;
    }
    free(blocks);
    return num_blocks * 2;  // return length of encrypted message
}

// decrypt a message using the private key
int decrypt(unsigned char* encrypted_message, int encrypted_message_len, int d, int n, unsigned char* decrypted_message){
    int i;
    int num_blocks = encrypted_message_len / 2;
    int* blocks = (int*)malloc(num_blocks * sizeof(int));
    for(i = 0; i < encrypted_message_len; i += 2){
        blocks[i / 2] = (encrypted_message[i] << 8) | encrypted_message[i + 1];
    }
    for(i = 0; i < num_blocks; i++){
        blocks[i] = (int)pow(blocks[i], d) % n;
        decrypted_message[i * 2] = (blocks[i] >> 8) & 0xFF;
        decrypted_message[i * 2 + 1] = blocks[i] & 0xFF;
    }
    free(blocks);
    return num_blocks * 2;  // return length of decrypted message
}

int main(){
    int p = 61;  // large prime number
    int q = 53;  // another large prime number
    int n = p * q;  // product of the two prime numbers
    int phi = (p - 1) * (q - 1);  // Euler's totient function of n
    int e = 17;  // public encryption key
    int d = private_key(p, q, e);  // private decryption key
    char message[500];
    printf("Enter message: ");
    scanf("%[^\n]%*c", message);
    printf("Message: %s\n", message);
    unsigned char* encrypted_message = (unsigned char*)malloc(500 * sizeof(unsigned char));
    int encrypted_message_len = encrypt(message, strlen(message), e, n, encrypted_message);
    printf("Encrypted message: ");
    int i;
    for(i = 0; i < encrypted_message_len; i++){
        printf("%02X", encrypted_message[i]);
    }
    printf("\n");
    unsigned char* decrypted_message = (unsigned char*)malloc(500 * sizeof(unsigned char));
    int decrypted_message_len = decrypt(encrypted_message, encrypted_message_len, d, n, decrypted_message);
    decrypted_message[decrypted_message_len] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
    free(encrypted_message);
    free(decrypted_message);
    return 0;
}