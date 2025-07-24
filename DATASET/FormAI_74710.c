//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main() {

  char input[100];
  printf("Welcome to the surreal input sanitizer! Please enter your input: \n");
  fgets(input, 100, stdin);

  // Applying the surrealistic transformation
  for(int i=0; i<strlen(input); i++) {
    switch(input[i]) {
      case 'a':
        input[i] = '!';
        break;
      case 'b':
        input[i] = ';';
        break;
      case 'c':
        input[i] = '@';
        break;
      case 'd':
        input[i] = '/';
        break;
      case 'e':
        input[i] = '>';
        break;
      case 'f':
        input[i] = '$';
        break;
      case 'g':
        input[i] = '|';
        break;
      case 'h':
        input[i] = '%';
        break;
      case 'i':
        input[i] = '(';
        break;
      case 'j':
        input[i] = '-';
        break;
      case 'k':
        input[i] = '§';
        break;
      case 'l':
        input[i] = '+';
        break;
      case 'm':
        input[i] = ')';
        break;
      case 'n':
        input[i] = '°';
        break;
      case 'o':
        input[i] = '?';
        break;
      case 'p':
        input[i] = '[';
        break;
      case 'q':
        input[i] = '#';
        break;
      case 'r':
        input[i] = ':';
        break;
      case 's':
        input[i] = '}';
        break;
      case 't':
        input[i] = '*';
        break;
      case 'u':
        input[i] = '.';
        break;
      case 'v':
        input[i] = ',';
        break;
      case 'w':
        input[i] = '"';
        break;
      case 'x':
        input[i] = '_';
        break;
      case 'y':
        input[i] = '>';
        break;
      case 'z':
        input[i] = '`';
        break;
      default:
        input[i] = input[i];
    }
  }

  // Displaying the surreal input
  printf("\nThank you for your input! \nHere is your surreal input: \n%s\n", input);

  return 0;
}