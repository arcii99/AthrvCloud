//FormAI DATASET v1.0 Category: Pattern printing ; Style: shocked
#include <stdio.h>

int main() {
  int count = 0;
  int spaces = 4;
  
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= spaces; j++) {
      printf(" ");
    }
    for (int j = 1; j <= i; j++) {
      printf("%d ", ++count);
    }
    printf("\n");
    spaces--;
  }
  
  spaces = 1;
  
  for (int i = 9; i >= 1; i--) {
    for (int j = 1; j <= spaces; j++) {
      printf(" ");
    }
    for (int j = 1; j <= i; j++) {
      printf("%d ", ++count);
    }
    printf("\n");
    spaces++;
  }
  
  return 0;
}