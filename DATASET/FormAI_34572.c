//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
  char input[100], output[100];
  printf("Enter a sentence in the Alien Language: ");
  fgets(input, 100, stdin);
  
  // code to translate Alien Language to English
  for(int i = 0; i < strlen(input); i++) {
    switch(input[i]) {
      case '@':
        output[i] = 'a';
        break;
      case '!':
        output[i] = 'b';
        break;
      case '#':
        output[i] = 'c';
        break;
      case '$':
        output[i] = 'd';
        break;
      case '%':
        output[i] = 'e';
        break;
      case '^':
        output[i] = 'f';
        break;
      case '&':
        output[i] = 'g';
        break;
      case '*':
        output[i] = 'h';
        break;
      case '(':
        output[i] = 'i';
        break;
      case ')':
        output[i] = 'j';
        break;
      case '_':
        output[i] = 'k';
        break;
      case '-':
        output[i] = 'l';
        break;
      case '+':
        output[i] = 'm';
        break;
      case '=':
        output[i] = 'n';
        break;
      case '[':
        output[i] = 'o';
        break;
      case '{':
        output[i] = 'p';
        break;
      case ']':
        output[i] = 'q';
        break;
      case '}':
        output[i] = 'r';
        break;
      case ';':
        output[i] = 's';
        break;
      case ':':
        output[i] = 't';
        break;
      case '<':
        output[i] = 'u';
        break;
      case ',':
        output[i] = 'v';
        break;
      case '>':
        output[i] = 'w';
        break;
      case '.':
        output[i] = 'x';
        break;
      case '?':
        output[i] = 'y';
        break;
      case '/':
        output[i] = 'z';
        break;
      case ' ':
        output[i] = ' ';
        break;
      default:
        output[i] = input[i];
        break;
    }
  }

  printf("Translated sentence: %s", output);

  return 0;
}