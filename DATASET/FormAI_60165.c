//FormAI DATASET v1.0 Category: Modern Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* plaintext, char* key);

int main(){
  char plaintext[50];
  char key[50];
  
  printf("Welcome to the surrealist encryption program! \n");
  printf("Please enter your plaintext message: \n");
  fgets(plaintext,50,stdin);
  printf("Please enter your key: \n");
  fgets(key,50,stdin);
  
  encrypt(plaintext, key);
  
  printf("Your encrypted message is: %s\n", plaintext);
  
  return 0;
}

void encrypt(char* plaintext, char* key){
  int key_len = strlen(key);
  int shift = 0;
  for (int i = 0; i < strlen(plaintext); i++){
    if (shift == key_len){
      shift = 0;
    }
    plaintext[i] = (((int)plaintext[i] - 97 + (int)key[shift] - 97) % 26) + 97;
    shift++;
  }
}