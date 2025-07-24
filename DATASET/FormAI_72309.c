//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: cheerful
// Welcome to the C Cat Language Translator!
// This program takes in a string of meows and translates it to English

#include <stdio.h>
#include <string.h>

int main() {
  char input[1000];

  printf("Hello! I am your friendly C Cat Language Translator. Please input your meows:\n");
  scanf("%[^\n]s", input);
  getchar();

  printf("Thank you for your meows! Here is your translation: \n");

  int len = strlen(input);
  int i;

  for (i = 0; i < len; i++) {
    if (input[i] == 'm') { // m = A
      printf("A");
    } else if (input[i] == 'e') { // e = B
      printf("B");
    } else if (input[i] == 'o') { // o = C
      printf("C");
    } else if (input[i] == 'w') { // w = D
      printf("D");
    } else if (input[i] == 'l') { // l = E
      printf("E");
    } else if (input[i] == 'v') { // v = F
      printf("F");
    } else if (input[i] == 'r') { // r = G
      printf("G");
    } else if (input[i] == 'c') { // c = H
      printf("H");
    } else if (input[i] == 'a') { // a = I
      printf("I");
    } else if (input[i] == 't') { // t = J
      printf("J");
    } else if (input[i] == 's') { // s = K
      printf("K");
    } else if (input[i] == 'b') { // b = L
      printf("L");
    } else if (input[i] == 'd') { // d = M
      printf("M");
    } else if (input[i] == 'f') { // f = N
      printf("N");
    } else if (input[i] == 'h') { // h = O
      printf("O");
    } else if (input[i] == 'g') { // g = P
      printf("P");
    } else if (input[i] == 'i') { // i = Q
      printf("Q");
    } else if (input[i] == 'j') { // j = R
      printf("R");
    } else if (input[i] == 'k') { // k = S
      printf("S");
    } else if (input[i] == 'n') { // n = T
      printf("T");
    } else if (input[i] == 'p') { // p = U
      printf("U");
    } else if (input[i] == 'q') { // q = V
      printf("V");
    } else if (input[i] == 'u') { // u = W
      printf("W");
    } else if (input[i] == 'x') { // x = X
      printf("X");
    } else if (input[i] == 'y') { // y = Y
      printf("Y");
    } else if (input[i] == 'z') { // z = Z
      printf("Z");
    } else if (input[i] == ' ') { // Space between words
      printf(" ");
    } else { // Any other character will be ignored
      continue;
    }
  }

  printf("\nThank you for using the C Cat Language Translator, hope you enjoyed it!\n");

  return 0;
}