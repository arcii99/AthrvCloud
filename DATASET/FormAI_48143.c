//FormAI DATASET v1.0 Category: Modern Encryption ; Style: artistic
#include<stdio.h>
#include<string.h>
#define MAX 100

int key[MAX][MAX];

void generateKeyMatrix(char *keyStr, int len){
  int i, j, k = 0;

  for(i = 0; i < MAX && k < len; i++){
    for(j = 0; j < MAX && k < len; j++){
      key[i][j] = keyStr[k];
      k++;
    }
  }
}

void encrypt(char *message, int row, int col){
  int i, j, k = 0;
  char cipher[row * col];
  
  memset(cipher, 0, sizeof(cipher));
  
  for(i = 0; i < MAX && k < row * col; i++){
    for(j = 0; j < MAX && k < row * col; j++){
      if(key[i][j]){
        cipher[k] = message[i * col + j];
        k++;
      }
    }
  }

  printf("Encrypted message is: %s", cipher);
}

int main(){
  char keyStr[] = "ARTISTICCODE";
  char message[] = "CHATBOTENCRYPTIONEXAMPLE";
  int i, j, k = 0, len, row, col;

  len = strlen(keyStr);
  row = col = MAX;

  generateKeyMatrix(keyStr, len);

  printf("Key Matrix: \n");
  for(i = 0; i < MAX; i++){
    for(j = 0; j < MAX; j++){
      printf("%c ", key[i][j]);
    }
    printf("\n");
  }

  printf("Message to be encrypted: %s\n", message);

  encrypt(message, row, col);

  return 0;
}