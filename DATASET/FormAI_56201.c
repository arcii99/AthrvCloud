//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  
  // Check if input file is provided
  if (argc < 2) {
    printf("Usage: %s [file]\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  // Declare variables
  char buf[BUF_SIZE];
  unsigned char hash[EVP_MAX_MD_SIZE];
  unsigned int hash_len = 0;
  EVP_MD_CTX *md_ctx;
  
  // Initialize OpenSSL library
  OpenSSL_add_all_digests();
  md_ctx = EVP_MD_CTX_new();
  
  // Get file name from arguments
  char *filename = argv[1];
  
  printf("Calculating MD5 hash of file %s\n", filename);
  
  // Open file
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    printf("Unable to open file %s\n", filename);
    exit(EXIT_FAILURE);
  }
  
  // Initialize the MD5 hash function
  EVP_DigestInit_ex(md_ctx, EVP_md5(), NULL);
  
  // Read data from the file and update the hash 
  size_t read_bytes;
  while ((read_bytes = fread(buf, 1, BUF_SIZE, fp)) != 0) {
    EVP_DigestUpdate(md_ctx, buf, read_bytes);
  }
  
  // Finalize the hash
  EVP_DigestFinal_ex(md_ctx, hash, &hash_len);
  
  // Print the hash in hexadecimal format
  printf("MD5 hash: ");
  for (int i = 0; i < hash_len; i++) {
    printf("%02x", hash[i]);
  }
  printf("\n");
  
  // Cleanup
  EVP_MD_CTX_free(md_ctx);
  fclose(fp);
  
  return 0;
}