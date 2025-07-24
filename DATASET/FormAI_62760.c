//FormAI DATASET v1.0 Category: Recursive ; Style: Cryptic
/*CrYpTiC ReCuRsIoN*/

#include <stdio.h>

void a();
void b();
void c();
void d();

void z() {
  printf("Z");
  a();
}

void y() {
  printf("Y");
  b();
}

void x() {
  printf("X");
  c();
}

void w() {
  printf("W");
  d();
}

void a() {
  printf("A");
  z();
}

void b() {
  printf("B");
  y();
}

void c() {
  printf("C");
  x();
}

void d() {
  printf("D");
  w();
}

int main() {
  z();
  return 0;
}