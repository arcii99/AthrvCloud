//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

void convertToMorseCode(char message[], int len);

int main() {
  char message[100];

  printf("Enter your message to convert to Morse code:\n");
  fgets(message, 100, stdin);
  message[strlen(message)-1] = '\0';

  convertToMorseCode(message, strlen(message));

  return 0;
}

void convertToMorseCode(char message[], int len) {
  char morse[27][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "};
  char morseCode[1000];
  int i, j, ctr;

  for (i = 0; message[i]!='\0'; i++) {
    if(message[i] >= 'A' && message[i] <= 'Z') {
        strcat(morseCode, morse[message[i]-65]);
    } else if(message[i] >= 'a' && message[i] <= 'z') {
        strcat(morseCode, morse[message[i]-97]);
    } else {
        strcat(morseCode, morse[26]);
    }
    strcat(morseCode, " ");
  }

  // Removing white spaces at the end
  ctr = 0;
  for (i = 0; morseCode[i] != '\0'; i++) {
      if (morseCode[i] != ' ') {
          morseCode[ctr++] = morseCode[i];
      }
  }
  morseCode[ctr] = '\0';

  // Printing Morse code
  printf("Morse code: %s", morseCode);
}