//FormAI DATASET v1.0 Category: Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encrypt(char *message, char *key) {
    srand(time(NULL));
    int msg_len = strlen(message), key_len = strlen(key);
    int key_sum = 0;
    for (int i = 0; i < key_len; i++) {
        key_sum += (int) key[i];
    }
    int key_offset = key_sum % 128;
    char *encrypted = malloc((msg_len + 1) * sizeof(char));
    for (int i = 0; i < msg_len; i++) {
        encrypted[i] = message[i] + key_offset * (rand() % 3 - 1);
    }
    encrypted[msg_len] = '\0';
    printf("Encrypted message: %s\n", encrypted);
    free(encrypted);
}

void decrypt(char *encrypted, char *key) {
    int enc_len = strlen(encrypted), key_len = strlen(key);
    int key_sum = 0;
    for (int i = 0; i < key_len; i++) {
        key_sum += (int) key[i];
    }
    int key_offset = key_sum % 128;
    char *decrypted = malloc((enc_len + 1) * sizeof(char));
    for (int i = 0; i < enc_len; i++) {
        decrypted[i] = encrypted[i] - key_offset * (rand() % 3 - 1);
    }
    decrypted[enc_len] = '\0';
    printf("Decrypted message: %s\n", decrypted);
    free(decrypted);
}

int main() {
    char message[1000], key[100];
    printf("Enter message to encrypt:\n");
    scanf("%[^\n]s", message);
    getchar();
    printf("Enter encryption key:\n");
    scanf("%s", key);
    encrypt(message, key);
    decrypt("M[E`Yx]h`l]Yhkfrjajew^tYd]`i", key);
    return 0;
}