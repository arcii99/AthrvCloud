//FormAI DATASET v1.0 Category: Pattern printing ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("\n\nWelcome to my amazing C pattern printing program!\n\n");

  // let's print a Christmas tree
  printf("Here is a pretty Christmas tree for you:\n\n");
  
  int levels = 5;
  for (int i = 0; i < levels; i++) {
    for (int j = 0; j < levels - i; j++) {
      printf(" ");
    }
    for (int k = 0; k < i * 2 + 1; k++) {
      printf("*");
    }
    printf("\n");
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < levels - 1; j++) {
      printf(" ");
    }
    printf("***\n");
  }
  printf("\n\nHo ho ho! Hope you enjoyed that little Christmas surprise.\n\n");

  // now let's print a pyramid
  printf("Ready for a PYRAMID? Here it is:\n\n");
  
  int size = 7;
  for (int i = 1; i <= size; i++) {
    for (int j = i; j < size; j++) {
      printf(" ");
    }
    for (int k = 1; k < i * 2; k++) {
      printf("*");
    }
    printf("\n");
  }
  printf("\n\nAmazing, right?\n\n");

  // and finally, let's print a diamond
  printf("One more for the road - a beautiful DIAMOND:\n\n");

  int diamond_size = 7;
  for (int i = 1; i <= diamond_size; i++) {
    for (int j = i; j < diamond_size; j++) {
      printf(" ");
    }
    for (int k = 1; k < i * 2; k++) {
      printf("*");
    }
    printf("\n");
  }
  for (int i = diamond_size - 1; i > 0; i--) {
    for (int j = i; j < diamond_size; j++) {
      printf(" ");
    }
    for (int k = 1; k < i * 2; k++) {
      printf("*");
    }
    printf("\n");
  }
  printf("\n\nI hope you had fun with my amazing C pattern printing program! Goodbye!\n\n");

  return 0;
}