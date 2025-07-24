//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* text_to_morse(char ch) {
  switch(ch) {
    case 'a':
      return ".-";
    case 'b':
      return "-...";
    case 'c':
      return "-.-.";
    case 'd':
      return "-..";
    case 'e':
      return ".";
    case 'f':
      return "..-.";
    case 'g':
      return "--.";
    case 'h':
      return "....";
    case 'i':
      return "..";
    case 'j':
      return ".---";
    case 'k':
      return "-.-";
    case 'l':
      return ".-..";
    case 'm':
      return "--";
    case 'n':
      return "-.";
    case 'o':
      return "---";
    case 'p':
      return ".--.";
    case 'q':
      return "--.-";
    case 'r':
      return ".-.";
    case 's':
      return "...";
    case 't':
      return "-";
    case 'u':
      return "..-";
    case 'v':
      return "...-";
    case 'w':
      return ".--";
    case 'x':
      return "-..-";
    case 'y':
      return "-.--";
    case 'z':
      return "--..";
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
    case '0':
      return "-----";
    case ' ':
      return "/";
    default:
      return "";
  }
}

int main() {
  char input[1000];
  printf("Enter text to convert to morse code: ");
  fgets(input, 1000, stdin);
  input[strcspn(input, "\n")] = '\0'; // Remove trailing newline
  int len = strlen(input);
  char output[5000];
  int out_i = 0;
  for(int i = 0; i < len; i++) {
    char* morse = text_to_morse(input[i]);
    if(morse[0] != '\0') {
      strcat(output, morse);
      strcat(output, " ");
      out_i += strlen(morse) + 1;
    }
  }
  printf("Morse code: %s\n", output);
  return 0;
}