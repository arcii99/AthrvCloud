//FormAI DATASET v1.0 Category: Modern Encryption ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void encrypt(char* input, char* output, char* key){
  //Function to encrypt the input string
  srand(time(NULL));
  int length = strlen(input);
  int key_length = strlen(key);
  for(int i=0; i<length; i++){
    int shift_value = rand() % key_length;
    output[i] = ((input[i] - 'a' + (key[shift_value] - 'a')) % 26) + 'a';
  }
}

void decrypt(char* input, char* output, char* key){
  //Function to decrypt the input string
  int length = strlen(input);
  int key_length = strlen(key);
  for(int i=0; i<length; i++){
    int shift_value = key[i % key_length] - 'a';
    int intermediate_result = input[i] - 'a' - shift_value;
    output[i] = (intermediate_result >= 0) ? (intermediate_result % 26) + 'a' : (26 + intermediate_result) + 'a';
  }
}

int main(){
  char input[100];
  char output[100];
  char key[100];

  printf("Enter the input string: ");
  scanf("%s", input);

  printf("Enter the key string: ");
  scanf("%s", key);

  encrypt(input, output, key);
  printf("Encrypted output: %s\n", output);

  decrypt(output, input, key);
  printf("Decrypted output: %s\n", input);

  return 0;
}