//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: detailed
#include <stdio.h>

int main() {
  int num;
  int prime;
  
  printf("Enter the number up to which you want to generate prime numbers: ");
  scanf("%d", &num);
  
  printf("Prime Numbers: 2 ");
  for (int i = 3; i <= num; i += 2) {
    prime = 1;
    for (int j = 3; j <= i/2; j += 2) {
      if (i%j == 0) {
        prime = 0;
        break;
      }
    }
    if (prime == 1)
      printf("%d ", i);
  }
  
  return 0;
}