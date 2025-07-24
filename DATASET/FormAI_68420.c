//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: active
#include <stdio.h>
#include <string.h>

int main(void) {
  char input[1000];
  int i, j;

  // Getting input from user
  printf("Enter a string in Alien language:");
  scanf("%[^'\n']s", input);

  // Converting to English language
  for(i = 0; i < strlen(input); i++) {
    switch(input[i]) {
      case '1':
        printf("a");
        break;
      case '2':
        printf("b");
        break;
      case '3':
        printf("c");
        break;
      case '4':
        printf("d");
        break;
      case '5':
        printf("e");
        break;
      case '6':
        printf("f");
        break;
      case '7':
        printf("g");
        break;
      case '8':
        printf("h");
        break;
      case '9':
        printf("i");
        break;
      case '0':
        printf("j");
        break;
      case '@':
        printf("k");
        break;
      case '#':
        printf("l");
        break;
      case '$':
        printf("m");
        break;
      case '%':
        printf("n");
        break;
      case '&':
        printf("o");
        break;
      case '*':
        printf("p");
        break;
      case '(':
        printf("q");
        break;
      case ')':
        printf("r");
        break;
      case '-':
        printf("s");
        break;
      case '=':
        printf("t");
        break;
      case '+':
        printf("u");
        break;
      case '[':
        printf("v");
        break;
      case '{':
        printf("w");
        break;
      case ']':
        printf("x");
        break;
      case '}':
        printf("y");
        break;
      case '\\':
        printf("z");
        break;
      case '|':
        printf(" ");
        break;
      default:
        printf("%c", input[i]);
        break;
    }
  }

  return 0;
}