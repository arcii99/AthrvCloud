//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Ada Lovelace
/*
 * Ada Lovelace Style C Text to Morse Code Conversion
 * Created by [Your Name]
 * Last modified [Date]
 */

#include <stdio.h>
#include <string.h>

// Morse Code Conversion Function
void MorseCode(char* message) {
  // Character to Morse Code Conversion Table
  char* morseCode[] = {
      ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
      ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
      "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....",
      "-....", "--...", "---..", "----.", "/",  // Slash represents space
  };
  
  // Loop through the message and convert each character to Morse Code
  for (int i = 0; i < strlen(message); i++) {
    // Convert character to uppercase for the conversion table lookup
    char c = toupper(message[i]);
    
    // Convert the character to Morse Code if it exists in the table
    if (c >= 'A' && c <= 'Z') {
      printf("%s ", morseCode[c - 'A']);
    } else if (c >= '0' && c <= '9') {
      printf("%s ", morseCode[c - '0' + 26]);
    } else if (c == ' ') {
      printf("/");
    }
  }
  
  printf("\n");  // New line character after Morse Code
}

int main() {
  // Example usage of the MorseCode function
  char message[] = "Hello, World!";
  printf("Original message: %s\n", message);
  printf("Morse Code: ");
  MorseCode(message);
  
  return 0;
}