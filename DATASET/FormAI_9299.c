//FormAI DATASET v1.0 Category: Pattern printing ; Style: futuristic
#include <stdio.h>

int main() {
  int i, j;

  //Printing the top half of the C pattern
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      if (i == 0) { //Printing the first line of 'C'
        printf("%c", 95);
      } else if (j == 0) { //Printing the vertical line of 'C'
        printf("%c", 124);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  //Printing the bottom half of the C pattern
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 5; j++) {
      if (j == 0) { //Printing the vertical line of 'C'
        printf("%c", 124);
      } else if (i == 3) { //Printing the last line of 'C'
        printf("%c", 95);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}