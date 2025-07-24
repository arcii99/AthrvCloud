//FormAI DATASET v1.0 Category: Recursive ; Style: recursive
#include<stdio.h>

int factorial(int n) {
  if (n <= 1) { 
    return 1; 
  } else {
    return n * factorial(n-1);
  }
}

int fibonacci(int n) {
  if (n <= 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int power(int base, int exponent) {
  if (exponent == 0) {
    return 1;
  } else {
    return base * power(base, exponent-1);
  }
}

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
  if (n == 1) {
    printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
    return;
  }
  hanoi(n-1, from_rod, aux_rod, to_rod);
  printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
  hanoi(n-1, aux_rod, to_rod, from_rod);
}

int main() {
  int n = 5;
  printf("%d! = %d\n", n, factorial(n));
  printf("Fibonacci sequence up to %d: ", n);
  for (int i=0; i<n; i++) {
    printf("%d ", fibonacci(i));
  }
  printf("\n");
  int base = 3;
  int exponent = 4;
  printf("%d^%d = %d\n", base, exponent, power(base, exponent));
  int num_disks = 3;
  hanoi(num_disks, 'A', 'C', 'B');
  return 0;
}