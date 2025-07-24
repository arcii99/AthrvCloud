//FormAI DATASET v1.0 Category: Pattern printing ; Style: invasive
#include <stdio.h>

int main() {
  char c ='*';
  int height = 10;
  int width = 11;
  int i, j;

  for (i = 1; i <= height; i++) {
    // Print top horizontal line 
    if (i == 1) {
      printf("  ");
      for (j = 1; j <= width-2; j++) {
        printf("%c", c);
      }
      printf("\n");
    }
    // Print slanted lines
    else if (i <= height/2) {
      printf("  ");
      for (j = 1; j <= i; j++) {
        printf(" ");
      }
      printf("%c", c);
      for (j = 1; j <= width-4-2*i; j++) {
        printf(" ");
      }
      printf("%c\n", c);
    }
    // Print middle line
    else if (i == height/2 + 1) {
      printf("  ");
      for (j = 1; j <= width/2-2; j++) {
        printf("%c", c);
      }
      printf(" C Pattern ");
      for (j = width/2+3; j <= width-2; j++) {
        printf("%c", c);
      }
      printf("\n");
    }
    // Print slanted lines
    else if (i > height/2 + 1 && i < height) {
      printf("  ");
      for (j = 1; j <= height-i; j++) {
        printf(" ");
      }
      printf("%c", c);
      for (j = 1; j <= width-4-2*(height-i); j++) {
        printf(" ");
      }
      printf("%c\n", c);
    }
    // Print bottom horizontal line 
    else {
      printf("  ");
      for (j = 1; j <= width-2; j++) {
        printf("%c", c);
      }
      printf("\n");
    }
  }

  return 0;
}