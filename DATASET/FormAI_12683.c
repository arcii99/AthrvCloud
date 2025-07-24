//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: protected
#include <stdio.h>
#include <string.h>

int main() {

  char alienLanguage[50];
  int length, index, i;

  // get input string
  printf("Enter an alien language word: ");
  fgets(alienLanguage, 50, stdin);
  length = strlen(alienLanguage);

  // translate each character
  for (index = 0; index < length; index++) {

    // translate vowels
    if (alienLanguage[index] == 'a') {
      printf("e");
    } else if (alienLanguage[index] == 'e') {
      printf("i");
    } else if (alienLanguage[index] == 'i') {
      printf("o");
    } else if (alienLanguage[index] == 'o') {
      printf("u");
    } else if (alienLanguage[index] == 'u') {
      printf("a");

    // translate consonants
    } else if (alienLanguage[index] == 'b') {
      printf("d");
    } else if (alienLanguage[index] == 'c') {
      printf("f");
    } else if (alienLanguage[index] == 'd') {
      printf("g");
    } else if (alienLanguage[index] == 'f') {
      printf("h");
    } else if (alienLanguage[index] == 'g') {
      printf("j");
    } else if (alienLanguage[index] == 'h') {
      printf("k");
    } else if (alienLanguage[index] == 'j') {
      printf("l");
    } else if (alienLanguage[index] == 'k') {
      printf("m");
    } else if (alienLanguage[index] == 'l') {
      printf("n");
    } else if (alienLanguage[index] == 'm') {
      printf("p");
    } else if (alienLanguage[index] == 'n') {
      printf("q");
    } else if (alienLanguage[index] == 'p') {
      printf("r");
    } else if (alienLanguage[index] == 'q') {
      printf("s");
    } else if (alienLanguage[index] == 'r') {
      printf("t");
    } else if (alienLanguage[index] == 's') {
      printf("v");
    } else if (alienLanguage[index] == 't') {
      printf("w");
    } else if (alienLanguage[index] == 'v') {
      printf("x");
    } else if (alienLanguage[index] == 'w') {
      printf("y");
    } else if (alienLanguage[index] == 'x') {
      printf("z");
    } else if (alienLanguage[index] == 'y') {
      printf("b");
    } else if (alienLanguage[index] == 'z') {
      printf("c");

    // print spaces and other characters unchanged
    } else if (alienLanguage[index] == ' ') {
      printf(" ");
    } else {
      printf("%c", alienLanguage[index]);
    }

  }

  printf("\n");

  return 0;
}