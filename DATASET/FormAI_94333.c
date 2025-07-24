//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: light-weight
#include <stdio.h>

#define MAX_SIZE 1000

// Function to convert character to ASCII art
void char_to_art(char c) {
  switch(c) {
    case 'A':
      printf("  /\\ \n /  \\ \n/____\\\n");
      break;
    case 'B':
      printf(" ____ \n| __ )\n|  _ \\\n|____/\n");
      break;
    case 'C':
      printf("  ___ \n / __|\n| (__ \n \___|\n");
      break;
    case 'D':
      printf(" ____ \n|  _ \\ \n| | | |\n|____/\n");
      break;
    case 'E':
      printf(" _____\n| ____|\n|  _|  \n|____|\n");
      break;
    case 'F':
      printf(" _____\n| ____|\n|  _|  \n|_|    \n");
      break;
    // add more characters here
    default:
      printf("     \n     \n     \n");
  }
}

// Function to convert text to ASCII art
void text_to_art(char* text) {
  int i = 0; // index for loop
  char c;    // current character
  // loop through each character in input string
  while(text[i] != '\0') {
    c = text[i];
    char_to_art(c);
    i++;
  }
}

int main() {
  char input[MAX_SIZE];

  printf("Enter your text: ");
  fgets(input, MAX_SIZE, stdin);

  text_to_art(input);

  return 0;
}