//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: real-life
#include <stdio.h>
#include <string.h>

void morseConversion(char *input);

int main() {
  printf("Please enter a word or phrase to convert to Morse code: ");
  char input[100];
  fgets(input, sizeof(input), stdin);

  int length = strlen(input);
  if (input[length - 1] == '\n') {
    input[length - 1] = '\0'; // remove newline character from input
  }

  morseConversion(input);

  return 0;
}

void morseConversion(char *input) {
  char *morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                     "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
  char *letters = "abcdefghijklmnopqrstuvwxyz";
  char output[1000] = "";

  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') { // if space, add space to output
      strcat(output, "/ ");
    } else {
      char c = tolower(input[i]);
      int index = strchr(letters, c) - letters; // get index of letter in alphabet array
      if (index >= 0 && index < 26) {
        strcat(output, morse[index]); // add Morse code equivalent to output
        strcat(output, " ");
      }
    }
  }

  printf("Morse code: %s\n", output);
}