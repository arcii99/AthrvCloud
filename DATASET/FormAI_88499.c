//FormAI DATASET v1.0 Category: Pattern printing ; Style: inquisitive
#include <stdio.h>

int main() {
  int size;
  printf("What size do you want the C pattern to be? ");
  scanf("%d", &size);
  
  // Make sure size is at least 3
  if (size < 3) {
    printf("Sorry, the C pattern must be at least size 3.\n");
    return 0;
  }
  
  // Print top horizontal line
  for (int i = 0; i < size; i++) {
    printf("*");
  }
  printf("\n");

  // Print vertical line
  for (int i = 0; i < size - 2; i++) {
    printf("*\n");
  }

  // Print bottom horizontal line
  for (int i = 0; i < size; i++) {
    printf("*");
  }
  printf("\n");

  // Print diagonal line
  for (int i = size - 2; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      printf(" ");
    }
    printf("*\n");
  }
  
  printf("Done!\n");
  return 0;
}