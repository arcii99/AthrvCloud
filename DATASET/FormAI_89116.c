//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter the alien language message: ");
  fgets(input, 100, stdin);

  // loop through each character of the string
  for(int i=0; i<strlen(input); i++) {
    if(input[i] == 'A') {
      printf("Z");
    } else if(input[i] == 'B') {
      printf("Y");
    } else if(input[i] == 'C') {
      printf("X");
    } else if(input[i] == 'D') {
      printf("W");
    } else if(input[i] == 'E') {
      printf("V");
    } else if(input[i] == 'F') {
      printf("U");
    } else if(input[i] == 'G') {
      printf("T");
    } else if(input[i] == 'H') {
      printf("S");
    } else if(input[i] == 'I') {
      printf("R");
    } else if(input[i] == 'J') {
      printf("Q");
    } else if(input[i] == 'K') {
      printf("P");
    } else if(input[i] == 'L') {
      printf("O");
    } else if(input[i] == 'M') {
      printf("N");
    } else if(input[i] == 'N') {
      printf("M");
    } else if(input[i] == 'O') {
      printf("L");
    } else if(input[i] == 'P') {
      printf("K");
    } else if(input[i] == 'Q') {
      printf("J");
    } else if(input[i] == 'R') {
      printf("I");
    } else if(input[i] == 'S') {
      printf("H");
    } else if(input[i] == 'T') {
      printf("G");
    } else if(input[i] == 'U') {
      printf("F");
    } else if(input[i] == 'V') {
      printf("E");
    } else if(input[i] == 'W') {
      printf("D");
    } else if(input[i] == 'X') {
      printf("C");
    } else if(input[i] == 'Y') {
      printf("B");
    } else if(input[i] == 'Z') {
      printf("A");
    } else {
      printf("%c", input[i]); // print the character as is if not in A-Z range
    }
  }

  return 0;
}