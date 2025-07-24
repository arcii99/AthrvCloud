//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>

void displayBinary(unsigned int num) {
  if (num / 2 != 0) {
    displayBinary(num / 2);
  }
  printf("%d", num % 2);
}

int main() {
  unsigned int a = 0xAAAA5555;
  printf("We have the number %d in decimal, but in binary it looks like:\n", a);
  displayBinary(a);
  printf("\n\nNow, let's take the bitwise complement of it:\n");
  a = ~a;
  displayBinary(a);
  printf("\n\nInteresting, right? Now, let's try some left shift...\n");
  a <<= 3;
  displayBinary(a);
  printf("\n\nAnd now let's right shift...\n");
  a >>= 2;
  displayBinary(a);
  printf("\n\nLet's try some bitwise AND operations. First, we need another number. How about 0x5555AAAA?\n");
  unsigned int b = 0x5555AAAA;
  printf("Our new number is %d in decimal and in binary it looks like:\n", b);
  displayBinary(b);
  printf("\n\nNow let's AND it with the complement of our first number:\n");
  a &= ~b;
  displayBinary(a);
  printf("\n\nThat's pretty cool! Let's try a bitwise OR. We'll OR it with 0xF0F0F0F0\n");
  unsigned int c = 0xF0F0F0F0;
  printf("Our new number is %d in decimal and in binary it looks like:\n", c);
  displayBinary(c);
  printf("\n\nAnd now for the OR operation:\n");
  a |= c;
  displayBinary(a);
  printf("\n\nThings are getting wild! How about we finish it off with a bitwise XOR with 0xCCCCCCCC?\n");
  unsigned int d = 0xCCCCCCCC;
  printf("Our new number is %d in decimal and in binary it looks like:\n", d);
  displayBinary(d);
  printf("\n\nAnd the XOR operation:\n");
  a ^= d;
  displayBinary(a);
  printf("\n\nWow, that was an insane journey into the world of bitwise operations! Thanks for joining me. See you next time.\n");

  return 0;
}