//FormAI DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
  #include <string.h>
  #include <ctype.h>

  // Function to encrypt text with our encryption algorithm
  void encrypt(char *text) {

    // Rot13 encryption
    for(int i = 0; text[i] != '\0'; i++) {
      if(isalpha(text[i])) {
        if(text[i] >= 'a' && text[i] <= 'm') {
          text[i] += 13;
        } else if(text[i] >= 'n' && text[i] <= 'z') {
          text[i] -= 13;
        } else if(text[i] >= 'A' && text[i] <= 'M') {
          text[i] += 13;
        } else if(text[i] >= 'N' && text[i] <= 'Z') {
          text[i] -= 13;
        }
      }
    }

    // Reverse encryption
    int length = strlen(text);
    for(int i = 0; i < length / 2; i++) {
      char temp = text[i];
      text[i] = text[length - i - 1];
      text[length - i - 1] = temp;
    }

    // Caesar encryption
    for(int i = 0; text[i] != '\0'; i++) {
      if(isalpha(text[i])) {
        if(text[i] >= 'a' && text[i] <= 'z') {
          text[i] = ((text[i] - 'a') + 3) % 26 + 'a';
        } else if(text[i] >= 'A' && text[i] <= 'Z') {
          text[i] = ((text[i] - 'A') + 3) % 26 + 'A';
        }
      }
    }

  }

  // Main function to test our encryption code
  int main() {

    // Get user input
    printf("Enter text to encrypt: ");
    char text[100];
    fgets(text, 100, stdin);

    // Remove newline character from fgets
    text[strcspn(text, "\n")] = '\0';

    // Encrypt the text
    encrypt(text);

    // Print out the encrypted text
    printf("Encrypted text: %s\n", text);

    return 0;
  }