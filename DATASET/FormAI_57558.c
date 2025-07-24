//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: relaxed
#include <stdio.h>
#include <string.h>

void textToMorse(char *);

int main() {
  char text[100];

  printf("Enter text to convert to Morse code:\n");
  fgets(text, sizeof(text), stdin);    // Accept input from user

  textToMorse(text);    // Call function to convert text to Morse code

  return 0;
}

// Function to convert text to Morse Code
void textToMorse(char *text) {
  char morse_code[36][6] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};

  int len = strlen(text);
  for (int i = 0; i < len; i++) {
    char ch = text[i];
    if (ch == ' ') {
      printf("  ");    // Double space for word boundary
    } else {
      if (ch >= 'A' && ch <= 'Z') {
        ch += 32;    // Convert uppercase to lowercase
      }
      int morse_index = ch - 'a';    // Get index of letter in Morse code array
      if (morse_index >= 0 && morse_index < 26) {
        printf("%s ", morse_code[morse_index]);    // Print Morse code for letter
      } else {
        printf("%c ", ch);    // For non-alphabetic characters, just print the character
      }
    }
  }
}