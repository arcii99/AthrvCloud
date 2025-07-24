//FormAI DATASET v1.0 Category: Pattern printing ; Style: happy
#include <stdio.h>

int main() {
  printf("Let's print a cheerful C pattern!\n");

  int size = 6;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      // Print C shape
      if (i == 0 && j != 0 && j != 5 || i == 5 && j != 0 && j != 5 || j == 0 && i != 0 && i != 5 || j == 5 && i != 0 && i != 5) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  printf("Wow, look at that beautiful C pattern!\n");
  return 0;
}