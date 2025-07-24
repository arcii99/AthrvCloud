//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: standalone
#include <stdio.h>
#include <string.h>

int main() {
  char phrase[256];

  printf("Enter a phrase in C Cat Language: ");
  fgets(phrase, sizeof(phrase), stdin);

  int len = strlen(phrase);

  for(int i=0; i<len; i++) {
    // replace "meow" with "printf("
    if(phrase[i] == 'm' && phrase[i+1] == 'e' && phrase[i+2] == 'o' && phrase[i+3] == 'w') {
      printf("printf(");
      i += 3;
    }
    // replace "ninja" with "\"%d\", "
    else if(phrase[i] == 'n' && phrase[i+1] == 'i' && phrase[i+2] == 'n' && phrase[i+3] == 'j' && phrase[i+4] == 'a') {
      printf("\"%%d\", ");
      i += 4;
    }
    // replace "whiskers" with ");"
    else if(phrase[i] == 'w' && phrase[i+1] == 'h' && phrase[i+2] == 'i' && phrase[i+3] == 's' && phrase[i+4] == 'k' && phrase[i+5] == 'e' && phrase[i+6] == 'r' && phrase[i+7] == 's') {
      printf(");\n");
      i += 7;
    }
    // replace "purr" with "return"
    else if(phrase[i] == 'p' && phrase[i+1] == 'u' && phrase[i+2] == 'r' && phrase[i+3] == 'r') {
      printf("return ");
      i += 3;
    }
    // replace "scratch" with "{"
    else if(phrase[i] == 's' && phrase[i+1] == 'c' && phrase[i+2] == 'r' && phrase[i+3] == 'a' && phrase[i+4] == 't' && phrase[i+5] == 'c' && phrase[i+6] == 'h') {
      printf("{\n");
      i += 6;
    }
    // replace "claw" with "}"
    else if(phrase[i] == 'c' && phrase[i+1] == 'l' && phrase[i+2] == 'a' && phrase[i+3] == 'w') {
      printf("}\n");
      i += 3;
    }
    // replace "catnip" with "scanf"
    else if(phrase[i] == 'c' && phrase[i+1] == 'a' && phrase[i+2] == 't' && phrase[i+3] == 'n' && phrase[i+4] == 'i' && phrase[i+5] == 'p') {
      printf("scanf");
      i += 5;
    }
    // replace "yarn" with "&"
    else if(phrase[i] == 'y' && phrase[i+1] == 'a' && phrase[i+2] == 'r' && phrase[i+3] == 'n') {
      printf("&");
      i += 3;
    }
    // replace "kitten" with "int"
    else if(phrase[i] == 'k' && phrase[i+1] == 'i' && phrase[i+2] == 't' && phrase[i+3] == 't' && phrase[i+4] == 'e' && phrase[i+5] == 'n') {
      printf("int");
      i += 5;
    }
    // replace "paw" with ";"
    else if(phrase[i] == 'p' && phrase[i+1] == 'a' && phrase[i+2] == 'w') {
      printf(";\n");
      i += 2;
    }
    // if character not found in C Cat Language, print as is
    else {
      printf("%c", phrase[i]);
    }
  }

  return 0;
}