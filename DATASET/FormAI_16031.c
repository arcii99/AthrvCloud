//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLetter(char, int);

int main() {
  char input[100];
  printf("Enter a string: ");
  fgets(input, 100, stdin);
  printf("\n");
  for (int i = 0; i < strlen(input); i++) {
    printLetter(input[i], i);
  }
  return 0;
}

void printLetter(char c, int position) {
  int offset = (position * 8);
  if (c >= 'A' && c <= 'Z') {
    printf("   **    \n");
    printf("  *  *   \n");
    printf(" *    *  \n");
    printf("*      * \n");
    printf("********\n");
    printf("*      * \n");
    printf("*      * \n");
    printf("\n");
  } else if (c >= 'a' && c <= 'z') {
    printf(" ******* \n");
    printf("       *\n");
    printf("      *\n");
    printf("     *\n");
    printf("  *******\n");
    printf(" *      *\n");
    printf("*       *\n");
    printf("\n");
  } else if (c >= '0' && c <= '9') {
    printf(" *******\n");
    printf("*       *\n");
    printf("*       *\n");
    printf(" *******\n");
    printf("       *\n");
    printf("*      *\n");
    printf(" ******\n");
    printf("\n");
  } else if (c == ' ') {
    printf("\n\n\n");
  } else {
    printf("    **\n");
    printf("   ****\n");
    printf("  ** **\n");
    printf(" **  **\n");
    printf("**   **\n");
    printf("**   **\n");
    printf("**   **\n");
    printf("\n");
  }
}