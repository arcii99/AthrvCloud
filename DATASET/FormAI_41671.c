//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char* convertToMorse(char c);
int main()
{
  char message[100], ch;
  int i, j;
  printf("Enter a message: ");
  fgets(message, sizeof(message), stdin);
  printf("\nMorse Code: \n");
  for (i = 0; i < strlen(message); i++)
  {
    ch = toupper(message[i]);
    if (ch == '\n')
      printf("\n");
    else if (isalpha(ch))
    {
      char* code = convertToMorse(ch);
      printf("%s ", code);
    }
    else
    {
      printf("%c ", ch);
    }
  }
  return 0;
}

char* convertToMorse(char c)
{
  switch (c)
  {
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
  default:
    return ""; // Unreachable code
  }
}