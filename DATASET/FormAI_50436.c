//FormAI DATASET v1.0 Category: Modern Encryption ; Style: excited
// Hey there coding enthusiasts! Are you ready for some exciting encryption magic?
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  printf("Welcome to the Modern Encryption program!\n");
  printf("This program will encrypt your message using a super cool method.\n");
  
  char message[1000];
  char* p_key;
  
  printf("Enter your message (max 1000 characters):\n");
  fgets(message, sizeof(message), stdin);
  
  int key_len;
  printf("Enter the length of the key (max 1000 characters):\n");
  scanf("%d", &key_len);
  getchar(); // To remove the newline character left by scanf
  
  p_key = (char*) calloc(key_len + 1, sizeof(char)); // To allocate memory for key
  
  printf("Enter the key (max %d characters):\n", key_len);
  fgets(p_key, key_len + 1, stdin);
  
  int i;
  int msg_len = strlen(message);
  int key_position = 0;
  
  for (i = 0; i < msg_len; i++) {
    int char_num = message[i];
    int key_num = p_key[key_position];
    int encrypted_num = char_num ^ key_num;
    message[i] = encrypted_num;
    
    key_position++;
    if (key_position == key_len) {
      key_position = 0;
    }
  }
  
  printf("\nYour encrypted message is: %s\n", message);
  free(p_key); // To free the memory used by key
  
  printf("\nThanks for using Modern Encryption program!\n");
  
  return 0;
}