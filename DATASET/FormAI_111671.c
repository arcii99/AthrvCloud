//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>

int main()
{
    RSA* rsa;
    FILE* publicKeyFile;
    FILE* privateKeyFile;
    char* publicKeyFilename = "publickey.pem";
    char* privateKeyFilename = "privatekey.pem";
    int numBits = 2048;
    unsigned long e = RSA_F4;
    int returnCode;

    rsa = RSA_generate_key(numBits, e, NULL, NULL);
    if(rsa == NULL)
    {
        printf("Failed to generate RSA key pair.\n");
        exit(EXIT_FAILURE);
    }

    publicKeyFile = fopen(publicKeyFilename, "wb");
    if(publicKeyFile == NULL)
    {
        printf("Failed to open public key file: %s\n", publicKeyFilename);
        RSA_free(rsa);
        exit(EXIT_FAILURE);
    }

    returnCode = PEM_write_RSAPublicKey(publicKeyFile, rsa);
    if(returnCode != 1)
    {
        printf("Failed to write public key to file: %s\n", publicKeyFilename);
        RSA_free(rsa);
        fclose(publicKeyFile);
        exit(EXIT_FAILURE);
    }

    privateKeyFile = fopen(privateKeyFilename, "wb");
    if(privateKeyFile == NULL)
    {
        printf("Failed to open private key file: %s\n", privateKeyFilename);
        RSA_free(rsa);
        fclose(publicKeyFile);
        exit(EXIT_FAILURE);
    }

    returnCode = PEM_write_RSAPrivateKey(privateKeyFile, rsa, NULL, NULL, 0, NULL, NULL);
    if(returnCode != 1)
    {
        printf("Failed to write private key to file: %s\n", privateKeyFilename);
        RSA_free(rsa);
        fclose(publicKeyFile);
        fclose(privateKeyFile);
        exit(EXIT_FAILURE);
    }

    printf("Public and private key files generated: %s, %s\n", publicKeyFilename, privateKeyFilename);

    RSA_free(rsa);
    fclose(publicKeyFile);
    fclose(privateKeyFile);

    return 0;
}