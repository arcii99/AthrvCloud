//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* toMorse(char c)
{
  switch(toupper(c)) // Converting letter to uppercase to simplify the case
  {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
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

void printMorse(char* s)
{
  int len = strlen(s);
  for(int i = 0; i < len; i++)
  {
    char* morse = toMorse(s[i]);
    if(strcmp(morse, "") == 0)
    {
      printf(" ");
    }
    else
    {
      printf("%s ", morse);
    }
  }
}

int main()
{
  printf("Welcome to the cheerful Morse code program!\n");
  printf("Type your message and press enter.\n");
  
  char input[256];
  scanf("%[^\n]%*c", input); // Reading input until newline character
  
  printf("Converting to Morse code...\n");
  printf("Here is your message in Morse code: \n");
  
  printMorse(input);
  
  printf("\nThank you for using the cheerful Morse code program! Have a nice day!");
  
  return 0;
}