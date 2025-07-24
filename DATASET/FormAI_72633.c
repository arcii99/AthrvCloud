//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Cryptic
#include <stdio.h>

int main() { 

  int x = 0x8da755b4, y = 0xc1749217, z = 0x816b52cb;

  int a = ((x >> 12) ^ (y << 8)) | ~(~z & 0xff);

  int b = ~x & ~(y << 8) & z;

  int c = ((x & y) | (x | y)) ^ z;

  int d = ((x & ~y) | (~x & y)) ^ (~z & 0xff);

  int e = ((x >> 24) & 0xff) | ((y >> 16) & 0xff00) | ((z >> 8) & 0xff0000) | ((a << 8) & 0xff000000);

  printf("x = 0x%x, y = 0x%x, z = 0x%x\n\n", x, y, z);

  printf("a = 0x%x\n\nb = 0x%x\n\nc = 0x%x\n\nd = 0x%x\n\ne = 0x%x\n", a, b, c, d, e);

  return 0;

}