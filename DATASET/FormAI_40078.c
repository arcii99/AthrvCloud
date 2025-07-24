//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: genious
#include <stdio.h>
#include <string.h>

int main() {
  char message[101];
  printf("Enter the text to convert to Morse code:\n");
  fgets(message, 101, stdin);
  // Remove the newline character from the end of the string
  message[strcspn(message, "\n")] = 0;

  // Define the Morse code mappings
  const char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                              "....", "..", ".---", "-.-", ".-..", "--", "-.",
                              "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                              "...-", ".--", "-..-", "-.--", "--..", "-----",
                              ".----", "..---", "...--", "....-", ".....",
                              "-....", "--...", "---..", "----.", "/", ""};

  // Convert the message to Morse code
  int i, j;
  for (i = 0; i < strlen(message); i++) {
    if (message[i] >= 'a' && message[i] <= 'z') {
      j = message[i] - 'a';
    } else if (message[i] >= 'A' && message[i] <= 'Z') {
      j = message[i] - 'A';
    } else if (message[i] >= '0' && message[i] <= '9') {
      j = message[i] - '0' + 26;
    } else {
      j = 28; // This is the index for the space character
    }
    printf("%s ", morse_code[j]);
  }
  printf("\n");

  return 0;
}