//FormAI DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>

//Function to encrypt the message
void encrypt(char message[], int key) {
  int i, ascii;

  printf("Encrypted Message: ");
  for(i=0; message[i] != '\0'; i++) {
    ascii = message[i];
    // Shift the ASCII Value of the character
    if(ascii >= 65 && ascii <= 90) {
      ascii = ((ascii - 65 + key) % 26) + 65;
    }
    else if(ascii >= 97 && ascii <= 122) {
      ascii = ((ascii - 97 + key) % 26) + 97;
    }
    printf("%c", ascii);
  }
  printf("\n");
}

int main() {
  char input[50];
  int key;

  //Get the string input from the user
  printf("Enter the message to encrypt: ");
  scanf("%[^\n]s", input);

  //Get the encryption key from the user
  printf("Enter the encryption key: ");
  scanf("%d", &key);

  //Encrypt the message
  encrypt(input, key);

  return 0;
}