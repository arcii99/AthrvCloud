//FormAI DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  printf("Welcome to the best encryption program you'll ever use!\n");
  printf("Enter a word or a sentence that you want to encrypt: ");

  char word[100];
  fgets(word, 100, stdin);
  int length = strlen(word) - 1;

  char encryptedWord[100];
  int i;

  for(i=0; i<length; i++) {
    encryptedWord[i] = word[i] + 3;  // Add 3 to the ASCII value of each character
  }
  encryptedWord[i] = '\0';

  printf("\nYour encrypted word is: %s\n", encryptedWord);
  return 0;
}