//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multivariable
#include <stdio.h>

int main() {
  char text[100];
  printf("Enter a text to convert to ASCII art: ");
  scanf("%s", text);

  int i, j;

  for (j = 0; j < 9; j++) {
    for (i = 0; i < strlen(text); i++) {
      if (text[i] == '\n')
        printf("\n");
      else if (text[i] == ' ')
        printf("    ");
      else if (text[i] == '-')
        printf(" _ ");
      else if (text[i] == '|') {
        printf("|");
        for (int k = 0; k < 5; k++)
          printf("\n|\n");
      } else if (text[i] == '/') {
        printf("  /");
        for (int k = 0; k < 4; k++)
          printf("\n /");
      } else if (text[i] == '\\') {
        printf("\\  ");
        for (int k = 0; k < 4; k++)
          printf("\n\\ ");
      } else if (text[i] == '_')
        printf("__");
      else
        printf(" %c ", text[i]);
    }
    printf("\n");
  }

  return 0;
}