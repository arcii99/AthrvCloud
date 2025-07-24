//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCK_SIZE 16

typedef struct {
    unsigned char state[256];
    unsigned char x;
    unsigned char y;
} RC4;

void swap(unsigned char *a, unsigned char *b) {
    unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

void key_schedule(RC4 *rc4, unsigned char *key, int key_length) {
    int i;
    
    for (i = 0; i < 256; i++) {
        rc4->state[i] = i;
    }
    
    rc4->x = 0;
    rc4->y = 0;
    
    for (i = 0; i < 256; i++) {
        rc4->y = (rc4->state[i] + rc4->y + key[i % key_length]) % 256;
        swap(&rc4->state[i], &rc4->state[rc4->y]);
    }
}

unsigned char get_pseudo_random_byte(RC4 *rc4) {
    rc4->x = (rc4->x + 1) % 256;
    rc4->y = (rc4->state[rc4->x] + rc4->y) % 256;
    swap(&rc4->state[rc4->x], &rc4->state[rc4->y]);
    return rc4->state[(rc4->state[rc4->x] + rc4->state[rc4->y]) % 256];
}

void encrypt(RC4 *rc4, unsigned char *message, int message_length, unsigned char *ciphertext) {
    int i;
    for (i = 0; i < message_length; i++) {
        ciphertext[i] = message[i] ^ get_pseudo_random_byte(rc4);
    }
}

void decrypt(RC4 *rc4, unsigned char *ciphertext, int ciphertext_length, unsigned char *message) {
    int i;
    for (i = 0; i < ciphertext_length; i++) {
        message[i] = ciphertext[i] ^ get_pseudo_random_byte(rc4);
    }
}

int main() {
    unsigned char key[] = "thisisakey";
    unsigned char message[] = "secretmessage";
    unsigned char ciphertext[BLOCK_SIZE];
    unsigned char decrypted_message[BLOCK_SIZE];
    
    RC4 rc4;
    
    srand((unsigned int)time(NULL));
    
    key_schedule(&rc4, key, sizeof(key));
    printf("Encrypting message: %s\n", message);
    encrypt(&rc4, message, sizeof(message), ciphertext);
    
    int i;
    printf("Ciphertext: ");
    for (i = 0; i < sizeof(message); i++) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");
    
    key_schedule(&rc4, key, sizeof(key));
    decrypt(&rc4, ciphertext, sizeof(ciphertext), decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
    
    return 0;
}