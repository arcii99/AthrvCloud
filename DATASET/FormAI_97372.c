//FormAI DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char input[100];
  char key[100];
  printf("Welcome to our unique C encryption program!\n");
  printf("Please enter the message you would like to encrypt: ");
  fgets(input, 100, stdin);
  printf("Please enter the secret key to be used for encryption: ");
  fgets(key, 100, stdin);
  
  //Removing newline characters from input and key
  input[strcspn(input, "\r\n")] = 0;
  key[strcspn(key, "\r\n")] = 0;
  
  int input_len = strlen(input);
  int key_len = strlen(key);
  
  //Making sure key is at least as long as the input
  while(key_len < input_len){
    strcat(key, key);
    key_len = strlen(key);
  }
  
  //XORing input with key
  for(int i = 0; i < input_len; i++){
    input[i] = input[i] ^ key[i];
  }
  
  printf("Encrypted message: %s", input);
  return 0;
}