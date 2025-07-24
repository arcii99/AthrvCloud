//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

void print_hex(const char* title, const unsigned char* data, const int len)
{
    printf("%s:", title);
    for(int i=0;i<len;i++)
        printf("%02X",data[i]);
    printf("\n");
}

int main()
{
    OpenSSL_add_all_digests();

    const unsigned char message[] = "Peaceful cryptography";
    const unsigned char key[] = "securepassword";
    unsigned char iv[] = {0x6b, 0xd1, 0xbe, 0xc8, 0x97, 0xc5, 0x8f, 0x02, 0x6e, 0x8e, 0x8a, 0x30, 0xbe, 0x94, 0xbe, 0x4a};
    unsigned char encrypted[MAX_INPUT+128];
    unsigned char decrypted[MAX_INPUT+1];
    int message_len = strlen((char*)message);
    int encrypted_len, decrypted_len;

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);
    EVP_EncryptUpdate(ctx, encrypted, &encrypted_len, message, message_len);
    EVP_EncryptFinal_ex(ctx, encrypted+encrypted_len, &encrypted_len);
    EVP_CIPHER_CTX_free(ctx);

    print_hex("Encrypted Message", encrypted, encrypted_len);

    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);
    EVP_DecryptUpdate(ctx, decrypted, &decrypted_len, encrypted, encrypted_len);
    EVP_DecryptFinal_ex(ctx, decrypted+decrypted_len, &decrypted_len);
    EVP_CIPHER_CTX_free(ctx);

    decrypted[decrypted_len] = '\0';
    printf("Decrypted Message: %s\n", decrypted);

    return 0;
}