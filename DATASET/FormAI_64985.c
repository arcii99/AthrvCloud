//FormAI DATASET v1.0 Category: Recursive ; Style: retro
#include <stdio.h>

void morse_code(char letter) {
  switch(letter) {
    case 'a':
      printf(".- ");
      break;
    case 'b':
      printf("-... ");
      break;
    case 'c':
      printf("-.-. ");
      break;
    case 'd':
      printf("-.. ");
      break;
    case 'e':
      printf(". ");
      break;
    case 'f':
      printf("..-. ");
      break;
    case 'g':
      printf("--. ");
      break;
    case 'h':
      printf(".... ");
      break;
    case 'i':
      printf(".. ");
      break;
    case 'j':
      printf(".--- ");
      break;
    case 'k':
      printf("-.- ");
      break;
    case 'l':
      printf(".-.. ");
      break;
    case 'm':
      printf("-- ");
      break;
    case 'n':
      printf("-. ");
      break;
    case 'o':
      printf("--- ");
      break;
    case 'p':
      printf(".--. ");
      break;
    case 'q':
      printf("--.- ");
      break;
    case 'r':
      printf(".-. ");
      break;
    case 's':
      printf("... ");
      break;
    case 't':
      printf("- ");
      break;
    case 'u':
      printf("..- ");
      break;
    case 'v':
      printf("...- ");
      break;
    case 'w':
      printf(".-- ");
      break;
    case 'x':
      printf("-..- ");
      break;
    case 'y':
      printf("-.-- ");
      break;
    case 'z':
      printf("--.. ");
      break;
    default:
      break;
  }
}

void convert_to_morse(char* message, int length) {
  if (length <= 0) {
    return;
  }
  
  convert_to_morse(message + 1, length - 1);
  
  morse_code(*message);
}

int main() {
  char message[100];
  
  printf("Enter a message: ");
  fgets(message, 100, stdin);
  
  convert_to_morse(message, strlen(message));
  
  printf("\n");
  
  return 0;
}