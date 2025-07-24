//FormAI DATASET v1.0 Category: Encryption ; Style: shape shifting
#include <stdio.h>
#include <string.h>

void encrypt(char word[], int key) {
  int i;
  for(i = 0; i < strlen(word); i++) {
    word[i] = word[i] + key;
  }
}

void decrypt(char word[], int key) {
  int i;
  for(i = 0; i < strlen(word); i++) {
    word[i] = word[i] - key;
  }
}

int main() {
  char word[100];
  int key, choice;

  printf("Enter a word to encrypt: ");
  scanf("%s", word);

  printf("Enter a key to encrypt the word: ");
  scanf("%d", &key);

  printf("\nEnter 1 to encrypt the word and 2 to decrypt the word: ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      encrypt(word, key);
      printf("The encrypted word is: %s\n", word);
      break;
    case 2:
      decrypt(word, key);
      printf("The decrypted word is: %s\n", word);
      break;
    default:
      printf("Invalid choice, please enter either 1 or 2.\n");
  }

  return 0;
}