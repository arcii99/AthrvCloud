//FormAI DATASET v1.0 Category: modern Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 100

char* encrypt(const char *message, const char *key);
char* decrypt(const char *encrypted_message, const char *key);

int main() {
    char message[MAX_LEN], key[MAX_LEN], *encrypted_message, *decrypted_message;
    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_LEN, stdin);
    printf("Enter the key: ");
    fgets(key, MAX_LEN, stdin);
    encrypted_message = encrypt(message, key);
    printf("Encrypted Message: %s", encrypted_message);
    decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted Message: %s", decrypted_message);
    free(encrypted_message);
    free(decrypted_message);
    return 0;
}

char* encrypt(const char *message, const char *key) {
    srand(time(NULL));
    int m_len = strlen(message), k_len = strlen(key);
    char *encrypted_message = calloc(m_len+1, sizeof(char));
    for(int i=0;i<m_len;i++) {
        encrypted_message[i] = message[i] + key[i%k_len] + rand()%100;
    }
    return encrypted_message;
}

char* decrypt(const char *encrypted_message, const char *key) {
    srand(time(NULL));
    int m_len = strlen(encrypted_message), k_len = strlen(key);
    char *decrypted_message = calloc(m_len+1, sizeof(char));
    for(int i=0;i<m_len;i++) {
        decrypted_message[i] = encrypted_message[i] - key[i%k_len] - rand()%100;
    }
    return decrypted_message;
}