//FormAI DATASET v1.0 Category: Encryption ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

int main(void){
  // Initialize key array
  char key[] = "secretkey";
  int key_len = strlen(key);
  // Initialize plaintext array
  char plaintext[] = "This is an example plaintext.";
  int plaintext_len = strlen(plaintext);
  // Initialize ciphertext array
  char ciphertext[plaintext_len+1];
  ciphertext[plaintext_len] = '\0';

  // Encryption process
  for(int i=0;i<plaintext_len;i++){
    ciphertext[i] = plaintext[i] ^ key[i%key_len];
  }

  // Print results
  printf("Plaintext: %s\n", plaintext);
  printf("Ciphertext: %s\n", ciphertext);

  // Decryption process
  char decrypted[plaintext_len+1];
  decrypted[plaintext_len] = '\0';
  
  for(int i=0;i<plaintext_len;i++){
    decrypted[i] = ciphertext[i] ^ key[i%key_len];
  }

  // Print decrypted message
  printf("Decrypted message: %s\n", decrypted);
  
  return 0;
}