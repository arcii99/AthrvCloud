//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>

int main() {
  int a = 30;
  int b = 45;
  int c = 0;
  int d = 0;
  int e = 0;
  
  c = a & b;
  d = a | b;
  e = ~a;
  
  printf("a & b = %d\n", c);
  printf("a | b = %d\n", d);
  printf("~a = %d\n", e);

  if (!(a & b)) {
    printf("a and b have no common bits set.\n");
  } else {
    printf("a and b have common bits set.\n");
  }
  
  if (!(a | b)) {
    printf("a and b have no bits set.\n");
  } else {
    printf("a and b have bits set.\n");
  }
  
  if (~a) {
    printf("The bitwise complement of a is not zero.\n");
  } else {
    printf("The bitwise complement of a is zero.\n");
  }

  return 0;
}