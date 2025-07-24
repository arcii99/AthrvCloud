//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>

// A mind-bending example of Bitwise Operations in action!
// This program calculates the alphanumeric value of a given word,
// by first converting each letter to its ASCII code, and then performing
// some bitwise operations on them.

int main() {
  char word[] = "mindbending";
  int length = sizeof(word) / sizeof(char) - 1;
  int sum = 0;

  for (int i = 0; i < length; i++) {
    int ascii = word[i];
    int bit = i % 4;
    int shift = bit * 8;
    int mask = 0xFF << shift;
    int code = (ascii & mask) >> shift;

    switch (bit) {
      case 0:
        code += 1;
        break;
      case 1:
        code -= 1;
        break;
      case 2:
        code *= 2;
        break;
      case 3:
        code /= 2;
        break;
    }

    sum += code;
  }

  printf("The alphanumeric value of \"%s\" is: %d", word, sum);
  return 0;
}