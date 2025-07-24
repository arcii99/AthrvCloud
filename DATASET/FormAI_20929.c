//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter text to convert to Morse code: ");
  fgets(input, 100, stdin);
  int len = strlen(input);
  
  char* morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
  // Morse code for letters A to Z
  
  char morse_output[len*3+1];
  
  // Convert text to Morse code
  for (int i = 0; i < len; i++) {
    if (input[i] == ' ') {
      strcat(morse_output, "   "); // 3 spaces between words
    } else {
      int index = input[i] - 'A';
      strcat(morse_output, morse[index]);
      strcat(morse_output, " "); // 1 space between letters
    }
  }
  
  printf("Morse code: %s", morse_output);
  
  return 0;
}