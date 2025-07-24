//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cryptic
#include <stdio.h>

int not(int a) {
  return !a;
}

int or(int a, int b) {
  return a || b;
}

int nand(int a, int b) {
  return !(a && b);
}

int and(int a, int b) {
  return not(nand(a,b));
}

int main() {
  int input1[4] = {0,0,1,1};
  int input2[4] = {0,1,0,1};
  int output[4];
  int i;

  for (i = 0; i < 4; i++) {
    output[i] = and(input1[i], input2[i]);
  }

  printf("Truth table for AND gate circuit:\n");
  printf("Input 1\tInput 2\tOutput\n");
  for (i = 0; i < 4; i++) {
    printf("%d\t%d\t%d\n", input1[i], input2[i], output[i]);
  }

  return 0;
}