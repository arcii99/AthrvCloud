//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

#define KEY_LENGTH 2048
#define PUBLIC_EXPONENT 65537
#define HASH_FUNCTION EVP_sha256()

int main()
{
  RSA *keypair;
  FILE *public_key_file, *private_key_file;
  EVP_PKEY *evp_key = NULL;

  keypair = RSA_generate_key(KEY_LENGTH, PUBLIC_EXPONENT, NULL, NULL);
  if(!keypair)
  {
    printf("Error generating RSA key pair.\n");
    return -1;
  }

  evp_key = EVP_PKEY_new();
  EVP_PKEY_assign_RSA(evp_key, keypair);
  
  public_key_file = fopen("public_key.pem", "wb");
  PEM_write_PUBKEY(public_key_file, evp_key);

  private_key_file = fopen("private_key.pem", "wb");
  PEM_write_PrivateKey(private_key_file, evp_key, NULL, NULL, 0, NULL, NULL);

  fclose(public_key_file);
  fclose(private_key_file);
  EVP_PKEY_free(evp_key);

  return 0;
}