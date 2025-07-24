//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: light-weight
#include<stdio.h>

int is_prime(int num) {
  int i;
  
  if(num == 2 || num == 3) {
    return 1;
  }

  if(num % 2 == 0 || num == 1) {
    return 0;
  }

  for(i = 3; i * i <= num; i += 2) {
    if(num % i == 0) {
      return 0;
    }
  }

  return 1;
}

int main() {
  int count = 0, num = 2, i;

  printf("Generating first 50 prime numbers:\n");

  while(count < 50) {
    if(is_prime(num)) {
      printf("%d ", num);
      count++;
    }
    num++;
  }

  printf("\n");
  return 0;
}