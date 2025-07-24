//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <string.h>

const char *morse_code[26] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

int main() {
  char text[100];
  printf("Enter text to convert to Morse code:\n");
  fgets(text, 100, stdin);

  int i, j;
  for(i = 0; i < strlen(text); i++) {
    char letter = text[i];
    if(letter >= 'a' && letter <= 'z') {
      printf("%s ", morse_code[letter - 'a']);
    } else if(letter >= 'A' && letter <= 'Z') {
      printf("%s ", morse_code[letter - 'A']);
    } else if(letter == ' ') {
      printf("  ");
    }
  }
  return 0;
}