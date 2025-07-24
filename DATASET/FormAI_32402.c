//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  
  int limit, i, j, flag;
  
  printf("Welcome to the Surrealist Prime Number Generator Program!\n\n");
  
  flag = 0;
  while(flag == 0) {
    printf("Enter the limit of numbers to check: ");
    if(scanf("%d", &limit) == 1) {
      flag = 1;
    } else {
      while(getchar() != '\n');
      printf("Invalid input! Please enter a positive integer.\n");
    }
  }
  
  printf("\nNow let's start generating some prime numbers!\n\n");
  
  for(i = 2; i <= limit; i++) {
    flag = 1;
    for(j = 2; j <= sqrt(i); j++) {
      if(i % j == 0) {
        flag = 0;
        break;
      }
    }
    if(flag == 1) {
      printf("%d is a surreal prime number!\n", i);
    } else {
      printf("%d is not surreal enough to be prime.\n", i);
    }
  }
  
  printf("\nDone! Thanks for using this program!\n");
  
  return 0;
}