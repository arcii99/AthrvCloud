//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: lively
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// helper function for converting a character to Morse code
char *charToMorse(char c) {
  switch(tolower(c)) {
    case 'a': return ".-";
    case 'b': return "-...";
    case 'c': return "-.-.";
    case 'd': return "-..";
    case 'e': return ".";
    case 'f': return "..-.";
    case 'g': return "--.";
    case 'h': return "....";
    case 'i': return "..";
    case 'j': return ".---";
    case 'k': return "-.-";
    case 'l': return ".-..";
    case 'm': return "--";
    case 'n': return "-.";
    case 'o': return "---";
    case 'p': return ".--.";
    case 'q': return "--.-";
    case 'r': return ".-.";
    case 's': return "...";
    case 't': return "-";
    case 'u': return "..-";
    case 'v': return "...-";
    case 'w': return ".--";
    case 'x': return "-..-";
    case 'y': return "-.--";
    case 'z': return "--..";
    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    default: return "";
  }
}

int main() {
  char input[100];
  printf("Enter a string to convert to Morse code: ");
  fgets(input, sizeof(input), stdin);
  // remove newline character from input
  input[strcspn(input, "\n")] = '\0';
  
  printf("Morse code conversion: ");
  for (int i = 0; input[i] != '\0'; i++) {
    // get Morse code equivalent of each character
    char *morse = charToMorse(input[i]);
    if (strcmp(morse, "") == 0) {
      printf(" ");
    } else {
      printf("%s ", morse);
    }
  }
  printf("\n");
  return 0;
}