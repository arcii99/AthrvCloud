//FormAI DATASET v1.0 Category: Scientific ; Style: shocked
#include <stdio.h>

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  if(n == 0) {
    printf("You entered ZERO!\n");
  } else {
    printf("You entered %d, which", n);
    if(n % 2 == 0) {
      printf(" is EVEN");
    } else {
      printf(" is ODD");
    }
    if(n < 0) {
      printf(" and NEGATIVE");
    } else if(n > 0) {
      printf(" and POSITIVE");
    }
    printf(".\n");
  }

  return 0;
}