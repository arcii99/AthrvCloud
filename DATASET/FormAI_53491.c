//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <string.h>

void translate(char phrase[]) {
  int i;
  printf("Translation: ");
  for (i = 0; i < strlen(phrase); i++) {
    switch (phrase[i]) {
      case 'a':
        printf("ka");
        break;
      case 'b':
        printf("zu");
        break;
      case 'c':
        printf("mi");
        break;
      case 'd':
        printf("te");
        break;
      case 'e':
        printf("ku");
        break;
      case 'f':
        printf("lu");
        break;
      case 'g':
        printf("ji");
        break;
      case 'h':
        printf("ri");
        break;
      case 'i':
        printf("ki");
        break;
      case 'j':
        printf("zu");
        break;
      case 'k':
        printf("me");
        break;
      case 'l':
        printf("ta");
        break;
      case 'm':
        printf("rin");
        break;
      case 'n':
        printf("to");
        break;
      case 'o':
        printf("mo");
        break;
      case 'p':
        printf("no");
        break;
      case 'q':
        printf("sa");
        break;
      case 'r':
        printf("shi");
        break;
      case 's':
        printf("ari");
        break;
      case 't':
        printf("chi");
        break;
      case 'u':
        printf("do");
        break;
      case 'v':
        printf("ru");
        break;
      case 'w':
        printf("mei");
        break;
      case 'x':
        printf("na");
        break;
      case 'y':
        printf("ra");
        break;
      case 'z':
        printf("sa");
        break;
      default:
        printf("%c", phrase[i]);
        break;
    }
  }
  printf("\n");
}

int main() {
  char input[100];

  printf("--- Alien Language Translator ---\n\n");
  printf("Enter phrase to translate: ");
  fgets(input, 100, stdin);

  translate(input);

  return 0;
}