//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <string.h>

void translate(char *input, char *output) {
  int len_input = strlen(input);
  
  for(int i = 0; i < len_input; i++) {
    switch(input[i]) {
      case 'A':
        strcat(output, "Qua");
        break;

      case 'B':
        strcat(output, "Dirk");
        break;

      case 'C':
        strcat(output, "Flurp");
        break;

      case 'D':
        strcat(output, "Plex");
        break;

      case 'E':
        strcat(output, "Zim");
        break;

      case 'F':
        strcat(output, "Snoo");
        break;

      case 'G':
        strcat(output, "Teez");
        break;

      case 'H':
        strcat(output, "Kax");
        break;

      case 'I':
        strcat(output, "Jook");
        break;

      case 'J':
        strcat(output, "Vex");
        break;

      case 'K':
        strcat(output, "Nor");
        break;

      case 'L':
        strcat(output, "Pra");
        break;

      case 'M':
        strcat(output, "Nap");
        break;

      case 'N':
        strcat(output, "Styx");
        break;

      case 'O':
        strcat(output, "Gaz");
        break;

      case 'P':
        strcat(output, "Mooz");
        break;

      case 'Q':
        strcat(output, "Rig");
        break;

      case 'R':
        strcat(output, "Bek");
        break;

      case 'S':
        strcat(output, "Dar");
        break;

      case 'T':
        strcat(output, "Looz");
        break;

      case 'U':
        strcat(output, "Rax");
        break;

      case 'V':
        strcat(output, "Nix");
        break;

      case 'W':
        strcat(output, "Zam");
        break;

      case 'X':
        strcat(output, "Quix");
        break;

      case 'Y':
        strcat(output, "Wib");
        break;

      case 'Z':
        strcat(output, "Gid");
        break;

      case ' ':
        strcat(output, "--");
        break;

      default:
        strcat(output, "Invalid character!");
        break;
    }

    strcat(output, " ");
  }
}

int main() {
  char input[100];
  char output[300] = "";

  printf("Enter a phrase to be translated: ");
  scanf("%[^\n]s", input);

  translate(input, output);

  printf("Translation: %s\n", output);

  return 0;
}