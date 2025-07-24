//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: excited
//Woo-hoo! Here we go! Time to convert some text to Morse code!

#include <stdio.h>
#include <string.h>

// Here are the codes for the characters in morse
char *alphabets[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
char *numbers[] = { "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." };
char *others[] = { ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", "."};

// Returns the morse code for a given character
char *getMorseCode(char ch) {
  if (ch >= 'a' && ch <= 'z') {
      return alphabets[ch - 'a'];
  }
  else if (ch >= 'A' && ch <= 'Z') {
      return alphabets[ch - 'A'];
  }
  else if (ch >= '0' && ch <= '9') {
      return numbers[ch - '0'];
  }
  else {
      switch(ch) {
        case '.':
          return others[0];
        case ',':     
          return others[1];
        case '?':
          return others[2];
        case '\'':
          return others[3];
        case '!':
          return others[4];
        case '/':
          return others[5];
        case '(':
          return others[6];
        case ')':
          return others[7];
        default:
          return "";
      }
  }
}

int main() {
  printf("Are you ready to convert some text to Morse code? Let's do this!\n");
  printf("Enter the text you want to convert: ");

  char input[256];
  fgets(input, 256, stdin);

  printf("The Morse code for the inputted text is: \n");

  // Loop through the inputted string
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') { // If the character is space, print space
        printf(" / ");
    }
    else { // Otherwise, get the morse code for the character and print it
        printf("%s ", getMorseCode(input[i]));
    }
  }

  printf("\nThat was so cool! Do you want to do it again?");

  return 0;
}