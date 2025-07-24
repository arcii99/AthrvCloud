//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <string.h>

// function to translate input string to alien language
void translateToAlien(char input[]) {
  int i;

  // loop through each character in the string
  for (i = 0; i < strlen(input); i++) {

    // if character is alphabetic, convert it to its alien equivalent
    if (isalpha(input[i])) {
      switch(tolower(input[i])) {
        case 'a': printf("%d", 1); break;
        case 'b': printf("%d", 2); break;
        case 'c': printf("%d", 3); break;
        case 'd': printf("%d", 4); break;
        case 'e': printf("%d", 5); break;
        case 'f': printf("%d", 6); break;
        case 'g': printf("%d", 7); break;
        case 'h': printf("%d", 8); break;
        case 'i': printf("%d", 9); break;
        case 'j': printf("%d", 10); break;
        case 'k': printf("%d", 11); break;
        case 'l': printf("%d", 12); break;
        case 'm': printf("%d", 13); break;
        case 'n': printf("%d", 14); break;
        case 'o': printf("%d", 15); break;
        case 'p': printf("%d", 16); break;
        case 'q': printf("%d", 17); break;
        case 'r': printf("%d", 18); break;
        case 's': printf("%d", 19); break;
        case 't': printf("%d", 20); break;
        case 'u': printf("%d", 21); break;
        case 'v': printf("%d", 22); break;
        case 'w': printf("%d", 23); break;
        case 'x': printf("%d", 24); break;
        case 'y': printf("%d", 25); break;
        case 'z': printf("%d", 26); break;
        default: break;
      }
    }
    else { // if character is not alphabetic, print it as is
      printf("%c", input[i]);
    }
  }
  printf("\n");
}

int main() {
  char input[100];

  printf("Enter a string to translate to Alien Language: ");
  fgets(input, 100, stdin);

  printf("The string in Alien Language is: ");
  translateToAlien(input);

  return 0;
}