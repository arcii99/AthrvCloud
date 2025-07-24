//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Donald Knuth
#include <stdio.h>

int main(void) {
  char ch;
  int i = 0, num = 0;

  printf("Enter a sentence with integers: ");

  while ((ch = getchar()) != '\n') {
     if (ch >= '0' && ch <= '9') {
        num = num * 10 + (ch - '0');
     } else if (ch == ' ') {
        printf("%d ", num);
        num = 0;            
     }
  }

  printf("%d\n", num);

  return 0;
}