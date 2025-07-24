//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: excited
#include <stdio.h>

int main() {
  int num, count=0, i, j; 
  printf("Get ready to generate prime numbers like never before!!\n");
  printf("Enter the number of prime numbers you want: ");
  scanf("%d", &num);
  printf("Hold tight, generating the first %d prime numbers\n", num);

  for(i=2; count<num; i++) {
    int prime=1; 
    for(j=2; j<i && prime; j++) {
      if(i%j == 0) {
        prime = 0;
      }
    }
    if(prime) {
      printf("%d ", i); 
      count++; 
    }
  }
  printf("\nTa-da! You just generated %d prime numbers like a boss!!\n", num);
  return 0;
}