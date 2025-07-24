//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: optimized
#include <stdio.h>
#include <string.h>

char* textToMorseCode(char character) {
  switch (character) {
    case 'A':
      return ".-";
    case 'B':
      return "-...";
    case 'C':
      return "-.-.";
    case 'D':
      return "-..";
    case 'E':
      return ".";
    case 'F':
      return "..-.";
    case 'G':
      return "--.";
    case 'H':
      return "....";
    case 'I':
      return "..";
    case 'J':
      return ".---";
    case 'K':
      return "-.-";
    case 'L':
      return ".-..";
    case 'M':
      return "--";
    case 'N':
      return "-.";
    case 'O':
      return "---";
    case 'P':
      return ".--.";
    case 'Q':
      return "--.-";
    case 'R':
      return ".-.";
    case 'S':
      return "...";
    case 'T':
      return "-";
    case 'U':
      return "..-";
    case 'V':
      return "...-";
    case 'W':
      return ".--";
    case 'X':
      return "-..-";
    case 'Y':
      return "-.--";
    case 'Z':
      return "--..";
    case '0':
      return "-----";
    case '1':
      return ".----";
    case '2':
      return "..---";
    case '3':
      return "...--";
    case '4':
      return "....-";
    case '5':
      return ".....";
    case '6':
      return "-....";
    case '7':
      return "--...";
    case '8':
      return "---..";
    case '9':
      return "----.";
    case ' ':
      return " ";
    default:
      return "";
  }
}

int main() {
  char input[100]; // Will store the input text
  char output[500]; // Will store the output in Morse code
  int i, j;

  printf("\nEnter text: ");
  fgets(input, 100, stdin);
  input[strcspn(input, "\n")] = 0; // Replace the newline character with NULL

  // Convert the text to Morse code
  for (i = 0, j = 0; i < strlen(input); i++) {
    char* morseCode = textToMorseCode(toupper(input[i]));
    if (strcmp(morseCode, "")) { // If it's not a space or an unsupported character
      strcat(output, morseCode);
      strcat(output, " ");
      j += strlen(morseCode) + 1;
    }
  }

  printf("\nMorse code:\n%s\n", output);

  return 0;
}