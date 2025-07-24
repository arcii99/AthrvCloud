//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: imaginative
/*
  A program to implement the Caesar Cipher encryption algorithm
  by shifting the characters of a plaintext message by a fixed amount of positions.
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main(void)
{
  char plaintext[MAX_SIZE];
  char ciphertext[MAX_SIZE];
  int shift;

  printf("Enter the plaintext message: ");
  fgets(plaintext, MAX_SIZE, stdin);

  printf("Enter the shift value: ");
  scanf("%d", &shift);

  for (int i = 0; i < strlen(plaintext); i++)
  {
    if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
    {
      // shift lowercase alphabets
      ciphertext[i] = 'a' + (plaintext[i] - 'a' + shift) % 26;
    }
    else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
    {
      // shift uppercase alphabets
      ciphertext[i] = 'A' + (plaintext[i] - 'A' + shift) % 26;
    }
    else
    {
      // non-alphabetic characters are copied as-is
      ciphertext[i] = plaintext[i];
    }
  }

  printf("The encrypted message is: %s\n", ciphertext);

  return 0;
}