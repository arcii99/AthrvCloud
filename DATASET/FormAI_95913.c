//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char plaintext[100], key[100], ciphertext[100];
  int i, j, k;

  printf("Enter the plaintext: ");
  scanf("%s", plaintext);

  printf("Enter the key: ");
  scanf("%s", key);

  int plaintextLength = strlen(plaintext);
  int keyLength = strlen(key);
  int keyCounter = 0;

  for (i = 0; i < plaintextLength; i++)
  {
    if (keyCounter == keyLength)
      keyCounter = 0;

    int temp = plaintext[i] + key[keyCounter];
    if (temp > 126)
      temp -= 95;

    ciphertext[i] = temp;
    keyCounter++;
  }

  printf("Encrypted message: ");
  for (i = 0; i < plaintextLength; i++)
  {
    printf("%c", ciphertext[i]);
  }

  return 0;
}