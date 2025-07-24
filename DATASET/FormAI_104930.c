//FormAI DATASET v1.0 Category: Bitwise operations ; Style: funny
#include <stdio.h>

int main() {
  unsigned char a = 0xAF;
  unsigned char b = 0xBE;

  printf("Welcome to the Bitwise Craziness program!\n");
  printf("Before the madness begins, let's take a look at our initial values.\n");
  printf("a = %X\n", a);
  printf("b = %X\n", b);

  printf("Now, let's XOR our values...\n");
  unsigned char c = a ^ b;
  printf("c = %X\n", c);

  printf("Next up, let's shift a over by 2 bits...\n");
  unsigned char d = a << 2;
  printf("d = %X\n", d);

  printf("Now for some wackier stuff - let's bitwise NOT b!\n");
  unsigned char e = ~b;
  printf("e = %X\n", e);

  printf("If you thought that was crazy, just wait until you see this!\n");
  unsigned char f = a | b;
  printf("f = %X\n", f);

  printf("It's time for our grand finale... the AND operator!\n");
  unsigned char g = a & b;
  printf("g = %X\n", g);

  printf("And that's a wrap! Thank you for joining us on this wild ride through Bitwise Craziness!\n");

  return 0;
}