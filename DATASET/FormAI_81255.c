//FormAI DATASET v1.0 Category: Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_INPUT_SIZE 1024
#define MAX_KEY_SIZE 16

char input[MAX_INPUT_SIZE];
char key[MAX_KEY_SIZE];
char cipher_text[MAX_INPUT_SIZE];
int cipher_length = 0;

void *encrypt(void *arg) {
    int i;
    char ch;

    for(i = 0; input[i] != '\0'; i++) {
        ch = input[i] ^ key[i % MAX_KEY_SIZE];
        cipher_text[i] = ch;
    }
    cipher_length = i;
    return NULL;
}

int main() {
    pthread_t thread;

    printf("Enter your message (up to 1024 characters):\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strlen(input) - 1] = '\0';

    printf("Enter your encryption key (up to 16 characters):\n");
    fgets(key, MAX_KEY_SIZE, stdin);
    key[strlen(key) - 1] = '\0';

    printf("Encrypting...\n");

    pthread_create(&thread, NULL, encrypt, NULL);
    pthread_join(thread, NULL);

    printf("Cipher text: ");
    for(int i = 0; i < cipher_length; i++) {
        printf("%02x", (unsigned char)cipher_text[i]);
    }
    printf("\n");

    return 0;
}