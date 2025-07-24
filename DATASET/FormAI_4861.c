//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: enthusiastic
#include <stdio.h>

int main() {
  char message[100]; // String to store user input
  int i, j;

  printf("Welcome to the ASCII Art Generator!\n");
  printf("Enter your message: ");
  scanf("%[^\n]", message); // Reads whole user input until newline character

  // Loop through every character of the message string
  for (i=0; message[i] != '\0'; i++) {
    // Loop through the ASCII codes of each character in the message
    for (j=0; j<=127; j++) {
      if (j == message[i]) {
        printf("*"); // Print "*" if ASCII code matches with the current character in the message
      }
      else {
        printf(" "); // Print " " for every other ASCII code
      }
    }
    printf("\n"); // Move onto the next line after every character is printed in ASCII art
  }

  printf("Thanks for using the ASCII Art Generator!\n");

  return 0;
}