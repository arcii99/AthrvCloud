//FormAI DATASET v1.0 Category: Game ; Style: recursive
#include <stdio.h>

int calcPower(int base, int exponent) {
  if (exponent == 0) {  // Basi case
    return 1;
  } else if (exponent % 2 == 0) {  // Recursive case for when exponent is even
    int half = calcPower(base, exponent / 2);
    return half * half;
  } else {  // Recursive case for when exponent is odd
    int half = calcPower(base, (exponent - 1) / 2);
    return half * half * base;
  }
}

int main() {
  int base = 2;
  int exponent = 8;
  int result = calcPower(base, exponent);
  printf("%d^%d = %d\n", base, exponent, result);
  return 0;
}