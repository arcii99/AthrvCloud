//FormAI DATASET v1.0 Category: Bitwise operations ; Style: happy
#include <stdio.h> // include standard input-output library for printf function

int main() {
  int a = 5; // initialize variable a with 5 in decimal
  int b = 9; // initialize variable b with 9 in decimal

  printf("a in decimal: %d\n", a); // print a in decimal format
  printf("b in decimal: %d\n", b); // print b in decimal format

  int c = a & b; // bitwise AND operation of a and b and store the result in c
  printf("c (a AND b) in decimal: %d\n", c); // print c in decimal format

  int d = a | b; // bitwise OR operation of a and b and store the result in d
  printf("d (a OR b) in decimal: %d\n", d); // print d in decimal format

  int e = ~a; // bitwise NOT operation of a and store the result in e
  printf("e (NOT a) in decimal: %d\n", e); // print e in decimal format

  int f = a ^ b; // bitwise XOR operation of a and b and store the result in f
  printf("f (a XOR b) in decimal: %d\n", f); // print f in decimal format

  int g = a << 2; // left shift operation of a by 2 and store the result in g
  printf("g (a << 2) in decimal: %d\n", g); // print g in decimal format

  int h = b >> 1; // right shift operation of b by 1 and store the result in h
  printf("h (b >> 1) in decimal: %d\n", h); // print h in decimal format

  return 0; // return 0 to indicate successful termination of program
}