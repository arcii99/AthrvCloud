//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

void convert(char str[]) {
  int i = 0;
  while (str[i] != '\0') { // loop through whole string
    switch (str[i]) {
      case 'A':
        printf(".-"); // Morse code for A
        break;
      case 'B':
        printf("-..."); // Morse code for B
        break;
      case 'C':
        printf("-.-."); // Morse code for C
        break;
      case 'D':
        printf("-.."); // Morse code for D
        break;
      case 'E':
        printf("."); // Morse code for E
        break;
      case 'F':
        printf("..-."); // Morse code for F
        break;
      case 'G':
        printf("--."); // Morse code for G
        break;
      case 'H':
        printf("...."); // Morse code for H
        break;
      case 'I':
        printf(".."); // Morse code for I
        break;
      case 'J':
        printf(".---"); // Morse code for J
        break;
      case 'K':
        printf("-.-"); // Morse code for K
        break;
      case 'L':
        printf(".-.."); // Morse code for L
        break;
      case 'M':
        printf("--"); // Morse code for M
        break;
      case 'N':
        printf("-."); // Morse code for N
        break;
      case 'O':
        printf("---"); // Morse code for O
        break;
      case 'P':
        printf(".--."); // Morse code for P
        break;
      case 'Q':
        printf("--.-"); // Morse code for Q
        break;
      case 'R':
        printf(".-."); // Morse code for R
        break;
      case 'S':
        printf("..."); // Morse code for S
        break;
      case 'T':
        printf("-"); // Morse code for T
        break;
      case 'U':
        printf("..-"); // Morse code for U
        break;
      case 'V':
        printf("...-"); // Morse code for V
        break;
      case 'W':
        printf(".--"); // Morse code for W
        break;
      case 'X':
        printf("-..-"); // Morse code for X
        break;
      case 'Y':
        printf("-.--"); // Morse code for Y
        break;
      case 'Z':
        printf("--.."); // Morse code for Z
        break;
      case ' ':
        printf("/"); // represents a space between words
        break;
      default: // handles all other characters
        printf("%c", str[i]); // simply print the character
        break;
    }
    printf(" "); // adds a space between each Morse code character or word
    i++;
  }
}

int main() {
  char str[100];
  printf("Enter text to translate to Morse code: ");
  fgets(str, 100, stdin);
  printf("You entered: %s\n", str);
  printf("The Morse code translation is: ");
  convert(str);
  return 0;
}