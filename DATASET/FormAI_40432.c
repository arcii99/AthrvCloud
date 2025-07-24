//FormAI DATASET v1.0 Category: Pattern printing ; Style: active
#include <stdio.h>

int main() {
  int length = 15;
  int mid = length / 2;
  
  // Printing the top part of the C
  for (int i = 0; i < mid; i++) {
    for (int j = 0; j < length; j++) {
      if (i == 0 || j == 0) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  
  // Printing the middle part of the C
  for (int i = 0; i < length; i++) {
    printf("*");
  }
  printf("\n");
  
  // Printing the bottom part of the C
  for (int i = mid + 1; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (i == length - 1 || j == 0) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  
  return 0;
}