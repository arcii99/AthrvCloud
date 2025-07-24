//FormAI DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cybEncrypt(char str[], int n) 
{
  int i;
  for(i = 0; i < n; i++)
    str[i] = str[i] + 2; // Increment each character by 2
}

void cybDecrypt(char str[], int n) 
{
  int i;
  for(i = 0; i < n; i++)
    str[i] = str[i] - 2; // Decrement each character by 2
}

int main() 
{
  char message[100];
  int option;

  printf("Enter your message: ");
  fgets(message, 100, stdin);

  printf("\nSelect an option:\n");
  printf("1. Encrypt\n2. Decrypt\n");
  scanf("%d", &option);

  switch(option) 
  {
    case 1:
      cybEncrypt(message, strlen(message));
      printf("\nEncrypted message: %s\n", message);
      break;

    case 2:
      cybDecrypt(message, strlen(message));
      printf("\nDecrypted message: %s\n", message);
      break;

    default:
      printf("\nInvalid option. Please try again.\n");
  }
  return 0;
}