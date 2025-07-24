//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: lively
#include <stdio.h>

int main() {
  // welcome message
  printf("Welcome to the ASCII Art Generator!\n");

  // ask user for input string
  printf("Enter a string: ");
  char str[50];
  fgets(str, 50, stdin);

  // get length of string
  int length = 0;
  while(str[length] != '\0') {
    length++;
  }

  // create ASCII art
  printf("\n");
  for(int i = 0; i < length; i++) {
    printf(" ");
    printf("__");
    for(int j = 0; j < 4; j++) {
      printf("_");
    }
    printf("__\n");
    printf("| ");
    for(int j = 0; j < 6; j++) {
      printf(" ");
    }
    printf(" |\n");
    printf("| ");
    printf("%c", str[i]);
    for(int j = 0; j < 4; j++) {
      printf(" ");
    }
    printf(" |\n");
    printf("|_");
    for(int j = 0; j < 6; j++) {
      printf("_");
    }
    printf("_|\n");
    printf("   ");
    for(int j = 0; j < 8; j++) {
      printf("~");
    }
    printf("\n\n");
  }

  // goodbye message
  printf("Thanks for using the ASCII Art Generator!\n");
  
  return 0;
}