//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

void print_hex(const char *title, const unsigned char *s, size_t len)
{
    printf("%s: ", title);
    for (size_t i = 0; i < len; ++i) {
        printf("%02X ", s[i]);
    }
    putchar('\n');
}

int main(void)
{
    const unsigned char key[] = "Th3_s3cr3t_K3y";
    const unsigned char iv[] = "Th3_1V_5tr1ng";
    const unsigned char original_message[] = "Th3_qu1ck_brown_f0x_jumps_0v3r_th3_l@zy_d0g.";
    unsigned char ciphertext[sizeof(original_message)];
    unsigned char decrypted_message[sizeof(original_message)];
    AES_KEY aes_key;

    printf("Original message: %s\n", original_message);

    AES_set_encrypt_key(key, sizeof(key) * 8, &aes_key);
    AES_cbc_encrypt(original_message, ciphertext, sizeof(original_message), &aes_key, iv, AES_ENCRYPT);

    print_hex("Ciphertext", ciphertext, sizeof(original_message));

    AES_set_decrypt_key(key, sizeof(key) * 8, &aes_key);
    AES_cbc_encrypt(ciphertext, decrypted_message, sizeof(ciphertext), &aes_key, iv, AES_DECRYPT);

    printf("Decrypted message: %.*s\n", (int)sizeof(decrypted_message), decrypted_message);

    return EXIT_SUCCESS;
}