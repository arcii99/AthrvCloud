//FormAI DATASET v1.0 Category: Arithmetic ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i = 5;
  float f = 7.2;
  double d = 10.75;
  char c = 'X';
  long int li = 1000000;
  short int si = 150;

  printf("The value of i is %d\n", i);
  printf("The value of f is %.2f\n", f);
  printf("The value of d is %.3lf\n", d);
  printf("The value of c is %c\n", c);
  printf("The value of li is %ld\n", li);
  printf("The value of si is %d\n", si);

  int sum = i + li + si;
  float product = f * d;
  double division = d / f;

  printf("The sum of i, li, and si is %d\n", sum);
  printf("The product of f and d is %.3f\n", product);
  printf("The division of d by f is %.3lf\n", division);

  int modulus = li % si;
  int post_inc = i++;
  int pre_dec = --si;

  printf("The modulus of li and si is %d\n", modulus);
  printf("The value of i after post-increment is %d\n", post_inc);
  printf("The value of si after pre-decrement is %d\n", pre_dec);

  return 0;
}