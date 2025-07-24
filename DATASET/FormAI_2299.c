//FormAI DATASET v1.0 Category: Syntax parsing ; Style: protected
#include <stdio.h>

int main() {
  int x = 10;
  
  if (x == 10) {
    char name[10] = "John Doe";
    printf("My name is %s\n", name);
  }
  
  for (int i = 0; i < 5; i++) {
    printf("i = %d\n", i);
  }
  
  switch (x) {
    case 1:
      printf("x is 1\n");
      break;
    case 10:
      printf("x is 10\n");
      break;
    default:
      printf("x is not 1 or 10\n");
      break;
  }
  
  int numbers[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    printf("numbers[%d] = %d\n", i, numbers[i]);
  }
  
  return 0;
}