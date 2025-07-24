//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <string.h>

// function to translate given string into C Alien Language
void translate(char* str) {
  int length = strlen(str);
  
  // loop through each character in the string
  for (int i = 0; i < length; i++) {
    switch (str[i]) {
      case 'a':
        printf("@"); // replace 'a' with '@'
        break;
      case 'e':
        printf("3"); // replace 'e' with '3'
        break;
      case 'i':
        printf("|"); // replace 'i' with '|'
        break;
      case 'o':
        printf("0"); // replace 'o' with '0'
        break;
      case 'u':
        printf("_"); // replace 'u' with '_'
        break;
      case 'y':
        printf("%"); // replace 'y' with '%'
        break;
      default:
        printf("%c", str[i]); // keep all other characters the same
    }
  }
}

int main() {
  char str[50]; // assuming the maximum length of string will be 50
  
  printf("Enter a string to translate: ");
  scanf("%s", str);
  
  printf("Translated string: ");
  translate(str);
  
  return 0;
}