//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];    // initialize character array to store user input
  printf("Enter a message to convert to Morse code: ");
  fgets(input, 100, stdin);    // read user input from standard input

  const char* morseCode[26] = {    // initialize morse code array
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
    "..-", "...-", ".--", "-..-", "-.--", "--.."
  };

  char output[500] = "";    // initialize character array to store morse code output
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {    // convert lowercase letters
      strcat(output, morseCode[input[i] - 'a']);
    } else if (input[i] >= 'A' && input[i] <= 'Z') {    // convert uppercase letters
      strcat(output, morseCode[input[i] - 'A']);
    } else if (input[i] == ' ') {    // add space between words
      strcat(output, " / ");
    }
    if (i != strlen(input) - 1 && input[i] != ' ') {    // add space between letters
      strcat(output, " ");
    }
  }

  printf("Morse code translation: %s\n", output);   // print morse code output

  return 0;
}