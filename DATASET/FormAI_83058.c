//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complete
#include<stdio.h>
#include<string.h>

// Function to convert character to Morse code
char* toMorse(char c) {
  switch(c) {
    case 'a':
    case 'A':
      return ".-";
    case 'b':
    case 'B':
      return "-...";
    case 'c':
    case 'C':
      return "-.-.";
    case 'd':
    case 'D':
      return "-..";
    case 'e':
    case 'E':
      return ".";
    case 'f':
    case 'F':
      return "..-.";
    case 'g':
    case 'G':
      return "--.";
    case 'h':
    case 'H':
      return "....";
    case 'i':
    case 'I':
      return "..";
    case 'j':
    case 'J':
      return ".---";
    case 'k':
    case 'K':
      return "-.-";
    case 'l':
    case 'L':
      return ".-..";
    case 'm':
    case 'M':
      return "--";
    case 'n':
    case 'N':
      return "-.";
    case 'o':
    case 'O':
      return "---";
    case 'p':
    case 'P':
      return ".--.";
    case 'q':
    case 'Q':
      return "--.-";
    case 'r':
    case 'R':
      return ".-.";
    case 's':
    case 'S':
      return "...";
    case 't':
    case 'T':
      return "-";
    case 'u':
    case 'U':
      return "..-";
    case 'v':
    case 'V':
      return "...-";
    case 'w':
    case 'W':
      return ".--";
    case 'x':
    case 'X':
      return "-..-";
    case 'y':
    case 'Y':
      return "-.--";
    case 'z':
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
      return "  ";
    default:
      return "";
  }
}

int main() {
  // Ask user for input
  char input[100];
  printf("Enter the text to convert to Morse code: ");
  fgets(input, 100, stdin);

  // Convert each character to Morse code and print to console
  printf("\nMorse code: ");
  for(int i=0; i<strlen(input); i++) {
    char* morse = toMorse(input[i]);
    if(strcmp(morse, "") != 0)  // Ignore spaces and non-alphanumeric characters
      printf("%s ", morse);
  }

  return 0;
}