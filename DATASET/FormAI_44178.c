//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define ASCII_WIDTH 80
#define ASCII_HEIGHT 80

char ascii[ASCII_HEIGHT][ASCII_WIDTH];

int main(void) {
  for (int i = 0; i < ASCII_HEIGHT; i++) {
    for (int j = 0; j < ASCII_WIDTH; j++) {
      ascii[i][j] = ' ';
    }
  }

  int x = 0, y = 0;
  char c;

  printf("Enter some text: ");
  while ((c = getchar()) != '\n' && x < ASCII_WIDTH && y < ASCII_HEIGHT) {
    ascii[y][x] = c;
    x++;
    if (x == ASCII_WIDTH) {
      y++;
      x = 0;
    }
  }

  for (int i = ASCII_HEIGHT - 1; i >= 0; i--) {
    for (int j = 0; j < ASCII_WIDTH; j++) {
      if (ascii[i][j] == ' ') {
        putchar(' ');
      } else {
        putchar(rand() % 2 == 0 ? '0' : '1');
      }
    }
    putchar('\n');
  }

  return 0;
}