//FormAI DATASET v1.0 Category: modern Encryption ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    int user_input_length;
    char user_input[16];
    unsigned char key[] = "mysecretkey12345";
    unsigned char iv[] = "vector1234567890";
    AES_KEY encryption_key, decryption_key;

    printf("Please enter a 16-digit message to be encrypted: ");
    scanf("%s", user_input);
    user_input_length = strlen(user_input);

    // Padding the message if it is not a 16-byte block
    if (user_input_length % 16 != 0) {
        int padding = 16 - (user_input_length % 16);
        memset(&(user_input[user_input_length]), 0, padding);
        user_input_length += padding;
    }

    unsigned char encrypted_output[user_input_length];
    unsigned char decrypted_output[user_input_length];
    AES_set_encrypt_key(key, 128, &encryption_key);
    AES_set_decrypt_key(key, 128, &decryption_key);

    // AES encryption
    AES_cbc_encrypt(user_input, encrypted_output, user_input_length, &encryption_key, iv, AES_ENCRYPT);

    printf("\nEncrypted message: ");
    for (int i = 0; i < user_input_length; i++) {
        printf("%02x", encrypted_output[i]);
    }

    // AES decryption
    AES_cbc_encrypt(encrypted_output, decrypted_output, user_input_length, &decryption_key, iv, AES_DECRYPT);
    printf("\nDecrypted message: %s\n", decrypted_output);

    return 0;
}