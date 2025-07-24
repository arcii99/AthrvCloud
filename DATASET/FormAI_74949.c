//FormAI DATASET v1.0 Category: Encryption ; Style: energetic
#include<stdio.h>

int main(){
  printf("Welcome to my C encryption program!\n");
  char message[100];
  int key, i;
  
  printf("Enter your message to be encrypted: ");
  scanf("%[^\n]s", message);
  
  printf("Enter a key value to encrypt your message: ");
  scanf("%d", &key);
  
  // Applying encryption algorithm
  for(i = 0; message[i] != '\0'; ++i){
    char ch = message[i];
    
    if(ch >= 'a' && ch <= 'z'){
      ch = 'a' + ((ch - 'a' + key) % 26);
    }
    else if(ch >= 'A' && ch <= 'Z'){
      ch = 'A' + ((ch - 'A' + key) % 26);
    }
    
    message[i] = ch;
  }
  
  printf("The encrypted message is: %s\n", message);
  
  // Applying decryption algorithm
  for(i = 0; message[i] != '\0'; ++i){
    char ch = message[i];
    
    if(ch >= 'a' && ch <= 'z'){
      ch = 'a' + (((ch - 'a' - key) + 26) % 26);
    }
    else if(ch >= 'A' && ch <= 'Z'){
      ch = 'A' + (((ch - 'A' - key) + 26) % 26);
    }
    
    message[i] = ch;
  }
  
  printf("The decrypted message is: %s\n", message);
  
  return 0;
}