//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: intelligent
#include <stdio.h>
#include <string.h>

char* toMorse(char c); // function declaration

int main() {

  char text[100];
  printf("Enter text to convert to Morse code: ");
  fgets(text, 100, stdin); // get user input
  text[strcspn(text, "\n")] = '\0'; // remove newline character from input
  
  printf("Morse code for the text is: ");

  int len = strlen(text);
  for(int i = 0; i < len; i++) {
    char c = text[i];
    if(c == ' ') {
      printf("   "); // three spaces represent empty space between words in Morse code
    } else {
      printf("%s ", toMorse(c)); // print Morse code for each character
    }
  }
  
  printf("\n");

  return 0;
}

// function to convert a character to its Morse code equivalent
char* toMorse(char c) {
  switch(c) {
    case 'a': case 'A':
      return ".-";
    case 'b': case 'B':
      return "-...";
    case 'c': case 'C':
      return "-.-.";
    case 'd': case 'D':
      return "-..";
    case 'e': case 'E':
      return ".";
    case 'f': case 'F':
      return "..-.";
    case 'g': case 'G':
      return "--.";
    case 'h': case 'H':
      return "....";
    case 'i': case 'I':
      return "..";
    case 'j': case 'J':
      return ".---";
    case 'k': case 'K':
      return "-.-";
    case 'l': case 'L':
      return ".-..";
    case 'm': case 'M':
      return "--";
    case 'n': case 'N':
      return "-.";
    case 'o': case 'O':
      return "---";
    case 'p': case 'P':
      return ".--.";
    case 'q': case 'Q':
      return "--.-";
    case 'r': case 'R':
      return ".-.";
    case 's': case 'S':
      return "...";
    case 't': case 'T':
      return "-";
    case 'u': case 'U':
      return "..-";
    case 'v': case 'V':
      return "...-";
    case 'w': case 'W':
      return ".--";
    case 'x': case 'X':
      return "-..-";
    case 'y': case 'Y':
      return "-.--";
    case 'z': case 'Z':
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
    default:
      return ""; // empty string represents invalid or unrecognized character
  }
}